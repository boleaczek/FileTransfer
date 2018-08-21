cmake_minimum_required(VERSION 3.11.2)
project (cmake_directory)
include_directories(
    include 
    include/data_manipulation 
    include/comunication
    include/comunication/comunicator)
file(GLOB SOURCES "src/*.cpp"
    "src/data_manipulation/*.cpp"
    "src/comunication/*.cpp")

add_executable(FileTransfer ${SOURCES})
