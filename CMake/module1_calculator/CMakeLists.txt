cmake_minimum_required(VERSION 3.28.1)
project(Calculator_Project VERSION 1.0.0)

message(STATUS "Adding library to the build...")
add_subdirectory(lib)                                                           # Recursively add the CMakeLists.txt from this sub-directory

message(STATUS "Adding sources to the executable...")
add_executable(calculator calculator.cpp)
add_executable(duplicate_calculator calculator.cpp)

message(STATUS "Adding link libraries...")
target_link_libraries(calculator PRIVATE math log)
target_link_libraries(duplicate_calculator PRIVATE math log)