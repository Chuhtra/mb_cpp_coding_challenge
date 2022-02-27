cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# create project
project(SmallIntentRecognizer VERSION 0.1)

add_executable(recognizer src/main.cpp)