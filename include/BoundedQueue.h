#pragma once

#include <queue>
#include <mutex>
#include <condition_variable>

template<typename T>
class BoundedQueue
{
private:
    std::queue<T> q;
    std::mutex mtx;
    std::condition_variable cv_full;
    std::condition_variable cv_empty;

    size_t maxSize;

public:
    BoundedQueue(size_t size) : maxSize(size) {}

    void push(const T& item)
    {
        std::unique_lock<std::mutex> lock(mtx);

        cv_full.wait(lock, [&] {
            return q.size() < maxSize;
        });

        q.push(item);

        cv_empty.notify_one();
    }

    T pop()
    {
        std::unique_lock<std::mutex> lock(mtx);

        cv_empty.wait(lock, [&] {
            return !q.empty();
        });

        T item = q.front();
        q.pop();

        cv_full.notify_one();

        return item;
    }
};