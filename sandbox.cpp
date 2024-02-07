/**
 * 实现的第一件事：
 * 传入文件，编译文件，执行文件，返回结果
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cstdio>

// 编译用户提交的C++源文件
bool compileCppFile(const std::string& filePath) {
    std::stringstream compileCmd;
    compileCmd << "clang++ -o executable " << filePath;

    // 执行编译命令
    int result = std::system(compileCmd.str().c_str());

    // 返回编译结果
    return result == 0;
}

// 运行可执行文件并保存输出结果到文件
bool runExecutable(const std::string& inputFilePath, const std::string& outputFilePath) {
    std::stringstream runCmd;
    runCmd << "./executable " << " > " << outputFilePath;

    // 执行运行命令
    int result = std::system(runCmd.str().c_str());

    // 返回运行结果
    return result == 0;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <source_file_path> <input_file_path> <output_file_path>" << std::endl;
        return 1;
    }

    // 获取用户提交的源文件路径、输入文件路径和输出文件路径
    std::string sourceFilePath = argv[1];
    std::string inputFilePath = argv[2];
    std::string outputFilePath = argv[3];

    // 编译用户提交的C++源文件
    if (!compileCppFile(sourceFilePath)) {
        std::cerr << "Compilation failed!" << std::endl;
        return 1;
    }

    // 运行可执行文件并保存输出结果到文件
    if (!runExecutable(inputFilePath, outputFilePath)) {
        std::cerr << "Execution failed!" << std::endl;
        return 1;
    }

    std::cout << "Execution completed successfully!" << std::endl;
    return 0;
}
