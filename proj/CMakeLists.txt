cmake_minimum_required(VERSION 3.0.0)

project(leetcode-practice VERSION 1.0)

include_directories(include)

aux_source_directory(src SRC_LIST)
aux_source_directory(src/1-200 SRC_LIST)
aux_source_directory(src/201-400 SRC_LIST)

add_executable(leetcode-practice ${SRC_LIST})