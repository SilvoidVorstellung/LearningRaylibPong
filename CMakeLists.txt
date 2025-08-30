cmake_minimum_required(VERSION 3.14)
project(
game
VERSION 0.1
DESCRIPTION "A simple pong game."
LANGUAGES C CXX
)

find_package(raylib 5.5 REQUIRED)

file(GLOB_RECURSE SRC
"src/*.cxx"
)

add_executable(${PROJECT_NAME} ${SRC})

target_include_directories(${PROJECT_NAME} PUBLIC include/)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
