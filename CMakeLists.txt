cmake_minimum_required(VERSION 3.10)
project(TimePoint)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)  

add_compile_options(/fsanitize=address)
add_link_options(/fsanitize=address)

add_executable(TimePoint
    main.cpp
    release.cpp
)