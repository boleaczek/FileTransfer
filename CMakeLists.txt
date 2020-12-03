cmake_minimum_required(VERSION 3.11.2)
project (cmake_directory)
include_directories(
    src
    src/communication
    src/communication/packets
    src/data_manager
    src/facades
    src/front_end
    src/tools)
file(GLOB SOURCES
    "src/facades/*.cpp"
    "src/front_end/*.cpp"
    "src/data_manager/*.cpp"
    "src/communication/*.cpp"
    "src/communication/packets/*.cpp"
    "src/tools/*.cpp")
file(GLOB TESTS_SOURCES
    "src/tests/*.cpp"
    "src/tests/communication/packets/*.cpp")

add_subdirectory(libs/googletest) #Build all the gtest stuff
include_directories(libs/googletest/include)

add_executable(FileTransfer ${SOURCES} "src/file_transfer.cpp")
add_executable(FileTransferTests ${TESTS_SOURCES} "src/tests/main.cpp")

target_link_libraries(FileTransferTests gtest gtest_main)