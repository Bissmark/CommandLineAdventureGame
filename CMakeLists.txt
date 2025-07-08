cmake_minimum_required(VERSION 3.10)
project(AdventureGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

add_executable(${PROJECT_NAME}
    main.cpp
    player.cpp
)