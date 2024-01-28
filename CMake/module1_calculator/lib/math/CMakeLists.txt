add_library(math src/addition.cpp src/division.cpp)
target_include_directories(math PUBLIC include)     # PUBLIC scope gives access to this include path to root level CMakeLists.txt