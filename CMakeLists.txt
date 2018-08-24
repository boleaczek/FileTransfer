cmake_minimum_required(VERSION 3.11.2)
project (cmake_directory)
include_directories(
    include 
    include/data_manipulation 
    include/network
    include/tools
    include/network/packets
    include/network/communication
    include/network/communication/client
    include/network/communication/server
    include/network/communication/factory)
file(GLOB SOURCES "src/*.cpp"
    "src/data_manipulation/*.cpp"
    "src/comunication/*.cpp"
    "src/tools/*.cpp")

add_executable(FileTransfer ${SOURCES})
