cmake_minimum_required(VERSION 3.9)
project(Followers)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "")

add_executable(
        Followers
        main.cpp
        src/follower.cpp
        src/Graphics.cpp
)

target_link_libraries(
        Followers
        sfml-graphics
        sfml-window
        sfml-system
)