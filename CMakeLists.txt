cmake_minimum_required(VERSION 3.5)

project(otus-03-homework)

add_executable(
    guess_the_number 
    app/src/main.cpp
    app/src/random_value.cpp
    app/src/save_to_file.cpp
)

set_target_properties(
    guess_the_number

PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)