#pragma once

#include "../../../communication/packets/Packet.h"
#include "gtest/gtest.h"

using Packet = communication::packets::Packet;
using MessageType = communication::packets::MessageType;

int CharPtrToInt(char * bytes, bool little_endian)
{

    int result = 0;
    int start = sizeof(result);
    int end = 0;
    int step = -1;

    if(!little_endian)
    {
        start = 0;
        end = sizeof(result);
        step = 1;
    }

    for (int n = start; n >= end; n += step)
    {
        result = (result << 8) + (unsigned char)bytes[n];
    }

    return result;
}

TEST(PacketTest, Serialize_IsFilePacket_ReturnsCorrectStream) {
    Packet packet { MessageType::file };
    auto serialized = packet.Serialize().str();
    
    auto bytes = new char[sizeof(int)];
    std::copy(serialized.c_str(), serialized.c_str() + serialized.length() + 1, bytes);
    
    auto result = CharPtrToInt(bytes, true);
    ASSERT_EQ(result, 0);
}


TEST(PacketTest, Deserialize_ReceivesCorrectStream_ReturnsCorrectObject) {
}