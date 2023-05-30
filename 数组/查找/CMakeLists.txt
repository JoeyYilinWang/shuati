cmake_minimum_required(VERSION 3.0)  # CMake版本要求

project(split_find)  # 项目名称

set(CMAKE_CXX_STANDARD 11)  # C++标准版本

# 添加源文件
set(
    SOURCES
    二分查找.cpp
)

# 添加头文件路径
include_directories(
    include
)

# 生成可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})


# 设置其他编译选项，如果需要的话
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
