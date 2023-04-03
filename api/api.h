#pragma once

namespace api
{
    enum class message_type
    {
        RED,
        GREEN,
        BLUE,
    };

    struct message
    {
        message_type type;
        int data;
    };

    void send(const message& message);
    message read();

}   // namespace api
