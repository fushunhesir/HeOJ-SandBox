//
// Created by Hanwei He on 2024/2/7.
//
#include <unistd.h>
#include <sys/wait.h>
#include "sys/time.h"
#include <printf.h>
#include "../include/base.h"
#include "../include/time.h"
#include "../include/parser.h"

void init_config(struct config *config_);


/**
 * 初始化配置清单
 *
 * @author hanwei.he
 * @param config_ 配置清单
 */
void init(int argc, char* argv[], struct config* config_) {
    // 调用解析器解析参数
    arg_handler(argc, argv);

    // 初始化配置清单
    init_config(config_);
}



/**
 * 运行用户代码
 * @param config_ 配置清单
 * @param result_ 运行结果
 */
void run(struct config* config_, struct result* result_) {
    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);
    int child_pid = fork();
    if(child_pid == 0) {
        execve(config_->executable_path, NULL, NULL);
    } else {
        int status;
        struct rusage rusage_;
        wait4(child_pid, &status, WSTOPPED, &rusage_);
        printf("father has get child %d\n", child_pid);
        gettimeofday(&end_time, NULL);
        result_->real_time = get_time_gap(start_time, end_time);
        result_->memory_size = rusage_.ru_maxrss >> 10;
    }
}



/**
 * 显示运行结果
 * @param result_ 运行结果
 */
void show(struct result result_) {
    printf("程序耗时：%llu ms\n程序消耗内存：%llu MB\n",
           result_.real_time,
           result_.memory_size);
}



/**
 * 用解析出来的参数初始化配置清单
 * @param config_ 配置清单
 * @note 此函数不暴露接口
 */
void init_config(struct config *config_) {

}
