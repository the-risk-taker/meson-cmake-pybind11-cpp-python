#include "api.h"
#include <iostream>
#include <queue>

namespace api
{
    static std::queue<message> queue;

    template<typename T>
    static constexpr T to_string(const message_type type)
    {
        switch (type)
        {
            case message_type::RED:
                return "RED";
            case message_type::GREEN:
                return "GREEN";
            case message_type::BLUE:
                return "BLUE";
        }

        return "UNKNOWN";
    }

    void send(const message& message)
    {
        queue.push(message);
        std::cout << "Sent message: " << to_string<const char*>(message.type) << " with data: 0x" << std::hex << message.data << '\n';
    }

    message read()
    {
        if (queue.size() > 0)
        {
            const auto message = queue.front();
            std::cout << "Read message: " << to_string<const char*>(message.type) << " with data: 0x" << std::hex << message.data << '\n';

            queue.pop();
            return message;
        }

        return {};
    }

}   // namespace api
