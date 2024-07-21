cmake_minimum_required(VERSION 3.5)

project(otus-03-homework)

add_executable(
    guess src/main.cpp
)

set_target_properties(
    guess
PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)