//
// Created by Hanwei He on 2024/2/7.
//

#ifndef HEOJ_BASE_H
#define HEOJ_BASE_H

#define  PROJECT_NAME "sandbox"
#define VERSION 0x010000

#define MAX_ARG 256
#define MAX_ENV 256

#include "sys/resource.h"


// 运行配置
struct config {
    rlim_t max_cpu_time;    // CPU运行时间限制
    rlim_t max_real_time;   // 程序运行用时限制
    rlim_t max_memory_size; // 程序消耗内存限制
    rlim_t max_proc_num;    // 程序占用进程限制

    char* executable_path;  // 可执行文件路径：用户代码编译后存放的位置
    char* output_path;      // 输出文件路径：程序的输出结果存放到该文件
    char* input_path;       // 输入文件路径：一般就是程序的测试样例参数
    char* exe_args[MAX_ARG + 1];        // 传递给程序的参数
    char* env_args[MAX_ENV + 1];        // 程序运行的环境参数
};

// 运行结果
struct result {
    rlim_t cpu_time;        // CPU运行时间
    rlim_t real_time;       // 程序运行用时
    rlim_t memory_size;     // 程序消耗内存

    char* output_path;      // 输出文件路径：程序的输出结果存放到该文件
};

void init(int, char**, struct config*);

void run(struct config*, struct result*);

void show(struct result result_);

#endif //HEOJ_BASE_H
