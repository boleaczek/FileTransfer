cmake_minimum_required(VERSION 3.11.2)
project (cmake_directory)
include_directories(
    src
    src/comunication
    src/comunication/packets
    src/data_manager
    src/facades
    src/front_end
    src/tools)
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



