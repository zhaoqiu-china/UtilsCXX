cmake_minimum_required(VERSION 3.1.0)

project(utils VERSION 1.0.0 LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/58d77fa8070e8cec2dc1ed015d66b454c8d78850.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


add_library(
    utils 
    src/utils.cc
)

target_include_directories(
    utils PRIVATE
    src/include
)

add_executable(
    main
    src/main.cc
)

target_link_libraries(
    main
    utils
)

# google test
enable_testing()

add_executable(
    test_utils
    tests/test_utils.cc
)
target_compile_definitions(
    test_utils PUBLIC
    RESOURCES_DIR="${CMAKE_CURRENT_SOURCE_DIR}/resources"
)
target_link_libraries(
    test_utils
    GTest::gtest_main
    utils
)
include(GoogleTest)
gtest_discover_tests(test_utils)
