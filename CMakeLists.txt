cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# create project
project(SmallIntentRecognizer VERSION 0.1)

file(GLOB SOURCES CONFIGURE_DEPENDS src/*.cpp)
add_executable(recognizer ${SOURCES})

# add unit testing through gtests

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  tests
  tests/tests.cpp
)
target_link_libraries(
  tests
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)
