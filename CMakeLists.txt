cmake_minimum_required(VERSION 3.11.2)
project (cmake_directory)
include_directories(
    include
    include/facades 
    include/data_manager 
    include/network
    include/tools
    include/front_end
    include/tools/packet_tools
    include/network/packets
    include/network/communication
    include/network/communication/client
    include/network/communication/server
    include/network/communication/factory)
file(GLOB SOURCES
    "src/facades/*.cpp"
    "src/front_end/*.cpp"
    "src/data_manager/*.cpp"
    "src/comunication/*.cpp"
    "src/comunication/packets/*.cpp"
    "src/tools/*.cpp")
file(GLOB TESTS_SOURCES "src/tests/*.cpp")

add_executable(FileTransfer ${SOURCES} "src/file_transfer.cpp")
add_executable(FileTransferTests ${TESTS_SOURCES} ${SOURCES})

find_package(Boost 1.67.0 COMPONENTS filesystem unit_test_framework)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
    target_link_libraries(FileTransfer ${Boost_LIBRARIES})
    target_link_libraries(FileTransferTests ${Boost_LIBRARIES})
    ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK) 
endif()



