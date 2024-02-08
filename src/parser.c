//
// Created by Hanwei He on 2024/2/8.
//

#include "../include/parser.h"
#include "../include/base.h"
#include "../include/utils.h"


/**
 * 命令行参数解析器
 * @param argc 命令行传入参数个数
 * @param argv 命令行参数的值
 */
void arg_handler(int argc, char* argv[]) {
    // 设置命令行参数
    arg_table[0] = (help = arg_lit0(NULL, "help", "Display help and exit")); // --help
    arg_table[1] = (version = arg_lit0(NULL, "version", "Display the version and exit"));
    arg_table[2] = (max_cpu_time = arg_intn(NULL, "max_cpu_time", INT_PLACEHOLDER, 0, 1, "max cpu running time(ms)"));
    arg_table[3] = (max_real_time = arg_intn(NULL, "max_real_time", INT_PLACEHOLDER, 0, 1, "max real running time(ms)"));
    arg_table[4] = (max_proc_num = arg_intn(NULL, "max_proc_num", INT_PLACEHOLDER, 0, 1, "max running process number"));
    arg_table[5] = (max_memory_size = arg_strn(NULL, "max_memory_size", STR_PLACEHOLDER, 0, 1, "max memory size"));
    arg_table[6] = (executable_path = arg_str1(NULL, "executable_path", STR_PLACEHOLDER, "executable path"));
    arg_table[7] = (input_path = arg_strn(NULL, "input_path", STR_PLACEHOLDER, 0, 1, "executable path"));
    arg_table[8] = (output_path = arg_strn(NULL, "output_path", STR_PLACEHOLDER, 0, 1, "out put path"));
    arg_table[9] = (exe_args = arg_strn(NULL, "exe_args", STR_PLACEHOLDER, 0, 255, "execute params"));
    arg_table[10] = (env_args = arg_strn(NULL, "env_args", STR_PLACEHOLDER, 0, 255, "execute program params"));
    arg_table[11] = (end = arg_end(10));

    // 解析参数
    int nerrors = arg_parse(argc, argv, arg_table);

    // 特殊处理help、version参数
    if(help->count > 0) {
        print_man();
        quit(0);
    }

    if(version->count > 0) {
        print_version();
        quit(0);
    }

    // 出现错误
    if(nerrors > 0) {
        print_errors();
        // TODO: 修改异常号
        quit(0);
    }
}

