#pragma once

#include <queue>
#include <mutex>
#include <condition_variable>

template<typename T>
class ThreadSafeQueue
{
private:
    std::queue<T> queue_;
    std::mutex mutex_;
    std::condition_variable cv_;

public:

    void push(const T& value)
    {
        std::lock_guard<std::mutex> lock(mutex_);
        queue_.push(value);
        cv_.notify_one();
    }

    T pop()
    {
        std::unique_lock<std::mutex> lock(mutex_);

        cv_.wait(lock, [this]
        {
            return !queue_.empty();
        });

        T value = queue_.front();
        queue_.pop();

        return value;
    }

    bool empty()
    {
        std::lock_guard<std::mutex> lock(mutex_);
        return queue_.empty();
    }
};