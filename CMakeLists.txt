cmake_minimum_required(VERSION 3.16)
project(TheMollusk)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES src/*.cpp include/*.h)

add_executable(TheMollusk ${SOURCES})
# Setting parameters for raylib
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # or games

add_subdirectory(libs/raylib-4.1 ./libs/raylib)
target_link_libraries(TheMollusk PRIVATE raylib)
