cmake_minimum_required(VERSION 3.5)

project(bulk LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(bulk main.cpp Command.cpp Block.cpp BlockBuilder.cpp BlockWriter.cpp FileWriter.cpp ConsoleWriter.cpp)
