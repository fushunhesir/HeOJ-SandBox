cmake_minimum_required(VERSION 3.0)
project(HeOJ)

# 添加可执行文件的源文件
add_executable(sandbox sanbox/sandbox.cpp)

# 设置编译后的可执行文件存放位置
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# 将可执行文件安装到指定目录
install(TARGETS evaluator DESTINATION bin)
