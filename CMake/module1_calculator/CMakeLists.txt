cmake_minimum_required(VERSION 3.0.0)
project(Calculator_Project VERSION 1.0.0)

add_subdirectory(lib)                                                           # Recursively add the CMakeLists.txt from this sub-directory

add_executable(calculator calculator.cpp)
add_executable(duplicate_calculator calculator.cpp)

target_link_libraries(calculator PRIVATE math log)
target_link_libraries(duplicate_calculator PRIVATE math log)