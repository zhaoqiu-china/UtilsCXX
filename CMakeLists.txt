cmake_minimum_required(VERSION 3.1.0)

project(utils VERSION 1.0.0 LANGUAGES CXX)

add_library(
    utils 
    src/utils.cc
)

target_include_directories(
    utils PRIVATE
    src/include
)