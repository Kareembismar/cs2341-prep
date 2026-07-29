cmake_minimum_required(VERSION 3.10)
project(backtester)
add_executable(backtester main.cpp backtester.cpp)
target_compile_options(backtester PRIVATE -Wall)