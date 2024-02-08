# 设置cmake最低版本要求
cmake_minimum_required(VERSION 3.5)

# 项目名称
project(HeOJ-sandbox)

add_library(argtable3 ./lib/argtable3/argtable3.c ./lib/argtable3/argtable3.h)

add_executable(judge_machine src/main.c
        include/base.h
        src/base.c
        src/time.c
        include/time.h
        include/parser.h
        src/parser.c
        include/utils.h
        src/utils.c)

target_link_libraries(judge_machine PRIVATE argtable3)