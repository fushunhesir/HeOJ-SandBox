//
// Created by Hanwei He on 2024/2/8.
//

#ifndef HEOJ_SANDBOX_PARSER_H
#define HEOJ_SANDBOX_PARSER_H

/**
 * 定义命令行参数、定义参数列表
 * @author hanwei.he
 */
#include "../lib/argtable3/argtable3.h"

// 传入参数个数上限
#define NUM_ALLOWED_ARG 10

// 配置参数
#define INT_PLACEHOLDER "<n>"
#define STR_PLACEHOLDER "<str>"

// 查看帮助、版本
struct arg_lit* help;
struct arg_lit* version;

// 设置CPU时间上限、运行时间上限、进程数量上限
struct arg_int* max_cpu_time;
struct arg_int* max_real_time;
struct arg_int* max_proc_num;

// 设置内存消耗上限、可执行文件路径、输出文件路径、输入文件路径
struct arg_str* max_memory_size;
struct arg_str* executable_path;
struct arg_str* output_path;
struct arg_str* input_path;

// 设置哨兵参数，表示到达参数列表末尾
struct arg_end* end;

// 定义参数列表用于存储上述参数
void* arg_table[NUM_ALLOWED_ARG + 1];

void arg_handler(int, char**);

#endif //HEOJ_SANDBOX_PARSER_H
