#define BOOST_TEST_MODULE tools_tests
#include <boost/test/unit_test.hpp>
#include <string>
#include "CommandParser.h"
#include "StringToEnumNumber.h"

BOOST_AUTO_TEST_SUITE(command_parser)

BOOST_AUTO_TEST_CASE(recieves_command_packet_input_returns_command_packet_data) 
{
    std::string input = "get testfile";
    CommandParser parser;
    PacketData pd = parser.Parse(input);
    BOOST_CHECK_EQUAL(pd.type, MessageType::command);
    BOOST_CHECK_EQUAL(pd.command, CommandType::get);
    BOOST_CHECK_EQUAL(pd.args[0], "testfile");
}

BOOST_AUTO_TEST_CASE(recieves_file_packet_input_returns_command_packet_data)
{
    std::string input = "file testfile";
    CommandParser parser;
    PacketData pd = parser.Parse(input);
    BOOST_CHECK_EQUAL(pd.type, MessageType::file);
    BOOST_CHECK_EQUAL(pd.args[0], "testfile");
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(string_to_enum_number)

BOOST_AUTO_TEST_CASE(recieves_valid_enum_number_returns_valid_string)
{
    MessageType t = MessageType::file;
    std::string msg_string = StringToEnumNumber::MessageTypeToString(t);
    BOOST_CHECK_EQUAL(msg_string, "file");
}

BOOST_AUTO_TEST_CASE(recieves_valid_string_returns_valid_enum_number)
{
    std::string msg_type_str("file");
    int msg_type_n = StringToEnumNumber::StringToMessageType(msg_type_str);
    BOOST_CHECK_EQUAL(msg_type_n, MessageType::file);
}

BOOST_AUTO_TEST_SUITE_END()