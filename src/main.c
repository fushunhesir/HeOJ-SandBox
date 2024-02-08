
#include <printf.h>
#include "../include/base.h"


//
// Created by Hanwei He on 2024/2/7.
//
int main(int argc, char* argv[]) {
    struct config config_;  // 用户代码运行配置
    struct result result_;  // 用户代码运行结果

    init(argc, argv, &config_);

    run(&config_, &result_);

    show(result_);

    return 0;
}
