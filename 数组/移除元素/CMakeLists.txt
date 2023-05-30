cmake_minimum_required(VERSION 3.0)

project(removeElement)

set(CMAKE_CXX_STANDARD 11)

set(
    SOURCES
    移除元素.cpp
)

# 添加头文件路径
include_directories(
)

# 生成可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})

