cmake_minimum_required(VERSION 3.0.0)
project(Calculator_Project VERSION 1.0.0)

add_subdirectory(lib)

add_executable(calculator calculator.cpp)
add_executable(duplicate_calculator calculator.cpp)

target_include_directories(calculator PRIVATE lib/math lib/log)
target_include_directories(duplicate_calculator PRIVATE lib/math lib/log)

target_link_libraries(calculator PRIVATE math log)
target_link_libraries(duplicate_calculator PRIVATE math log)