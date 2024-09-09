cmake_minimum_required(VERSION 3.29)
project(tts-test)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

include_directories(
        include
)

set(LIBRARY_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib/${CMAKE_SYSTEM_NAME}/${CMAKE_SYSTEM_PROCESSOR}")
link_directories(${LIBRARY_PATH})

add_executable(runTests tts-test.cpp)

target_link_libraries(runTests tts gtest)

target_link_libraries(tts PRIVATE curl)
