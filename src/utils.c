//
// Created by Hanwei He on 2024/2/8.
//
#include <stdlib.h>
#include "../include/utils.h"
#include "../lib/argtable3/argtable3.h"
#include "../include/parser.h"

void quit(int exit_code)
{
    arg_freetable(arg_table, sizeof(arg_table) / sizeof(arg_table[0]));
    exit(exit_code);
}

void print_errors()
{
    arg_print_errors(stdout, end, PROJECT_NAME);
    printf("Try '%s --help' for more information.\n", PROJECT_NAME);
}

void print_man()
{
    printf("Usage: %s", PROJECT_NAME);
    arg_print_syntax(stdout, arg_table, "\n\n");
    arg_print_glossary(stdout, arg_table, "  %-25s %s\n");
}

void print_version()
{
    printf("Version: %d.%d.%d\n", (VERSION >> 16) & 0xff, (VERSION >> 8) & 0xff, VERSION & 0xff);
}
