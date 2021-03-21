cmake_minimum_required(VERSION 3.2)
project(vectors)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(array_dvd ./src/01_array_dvd.cpp)
add_executable(array_functions ./src/02_array_with_functions.cpp)
add_executable(number_digits ./src/03_even_digit_numbers.cpp)


# linking
target_link_libraries(number_digits ${GTEST_BOTH_LIBRARIES})
