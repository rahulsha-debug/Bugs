cmake_minimum_required(VERSION 3.2)

project(hello VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)
enable_testing()

find_package(SystemCLanguage)

add_executable(hello 
  hello4.cpp)

target_link_libraries(hello
  PRIVATE
    SystemC::systemc)

add_test(NAME setup
  COMMAND hello)
