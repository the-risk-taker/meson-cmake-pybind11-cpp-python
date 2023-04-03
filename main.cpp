#include "api.h"
#include <iostream>
#include <random>

int random_int(const int from, const int to);

int main()
{
    std::cout << "C++ API client, starting...\n\n";

    api::message message {static_cast<api::message_type>(random_int(0, 2)), 42};

    api::send(message);
    message = api::read();
}

int random_int(const int from, const int to)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(from, to);

    return dist(mt);
}
