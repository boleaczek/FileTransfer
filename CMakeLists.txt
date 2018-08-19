cmake_minimum_required(VERSION 3.11.2)
project (cmake_directory)
include_directories(include include/data_manipulation include/communication)
file(GLOB SOURCES "src/*.cpp"
    "src/data_manipulation/*.cpp"
    "src/communication/*.cpp")

add_executable(FileTransfer ${SOURCES})
