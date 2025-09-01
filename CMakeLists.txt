cmake_minimum_required(VERSION 3.14)
project(
pong
VERSION 0.1
DESCRIPTION "A simple pong game."
LANGUAGES C CXX
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(raylib 5.5 QUIET)

if(NOT raylib_FOUND)
  include(FetchContent)
  fetchcontent_declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_PROGRESS true
    GIT_TAG "master"
  )
  fetchcontent_getproperties(raylib)
  if(NOT raylib_POPULATED)
    set(FETCHCONTENT_QUIET NO)
    fetchcontent_makeavailable(raylib)
  endif()
endif()

file(GLOB_RECURSE SRC
"src/*.cxx"
)

add_executable(${PROJECT_NAME} ${SRC})

target_include_directories(${PROJECT_NAME} PUBLIC include/)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
