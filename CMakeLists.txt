cmake_minimum_required(VERSION 3.15)

project(MiniRedis LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(miniredis
    src/main.cpp
    src/database.cpp
)

target_include_directories(miniredis
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang|AppleClang")
    target_compile_options(miniredis PRIVATE -Wall -Wextra -Wpedantic)
endif()