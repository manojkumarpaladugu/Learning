add_library(log src/log.cpp)
target_include_directories(log PUBLIC include)     # PUBLIC scope gives access to this include path to root level CMakeLists.txt