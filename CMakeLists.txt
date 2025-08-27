cmake_minimum_required(VERSION 3.14)
project(game)

find_package(raylib 5.5 REQUIRED)

file(GLOB_RECURSE SRC
"src/*.cxx"
"src/*.h"
)

add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
