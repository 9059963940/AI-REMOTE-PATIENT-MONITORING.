#include "../include/ApiServer.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

void ApiServer::start()
{
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_fd, (struct sockaddr*)&addr, sizeof(addr));

    listen(server_fd, 5);

    std::cout << "API Server running on http://localhost:8080\n";

    while(true)
    {
        int client = accept(server_fd, nullptr, nullptr);

        std::string response =
            "HTTP/1.1 200 OK\nContent-Type: text/plain\n\n"
            "Patient Monitoring System Running";

        send(client, response.c_str(), response.size(), 0);

        close(client);
    }
}