cmake_minimum_required(VERSION 3.29)
project(tts)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# include path
include_directories(
        include
        http
        google
        base64
        parameter
        include/external
)

# library path
set(LIBRARY_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib/${CMAKE_SYSTEM_NAME}/${CMAKE_SYSTEM_PROCESSOR}")
link_directories(${LIBRARY_PATH})

# output path
set(OUTPUT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/output/${CMAKE_BUILD_TYPE}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_PATH})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_PATH})

set(SOURCE_FILES
        ParameterBuilder.cpp
        TtsService.cpp
        http/RestfulClient.cpp
        google/GoogleTts.cpp
        base64/base64.cpp
)

add_library(tts SHARED
        ${SOURCE_FILES}
)

target_link_libraries(tts PRIVATE curl)

add_custom_command(TARGET tts POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${LIBRARY_PATH}
        ${OUTPUT_PATH}
)

add_custom_command(TARGET tts POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${OUTPUT_PATH}
        "${CMAKE_CURRENT_SOURCE_DIR}/test/lib/${CMAKE_SYSTEM_NAME}/${CMAKE_SYSTEM_PROCESSOR}"
)

add_subdirectory(test)