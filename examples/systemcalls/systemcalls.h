#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
// #include<stdio.h>
#include<stddef.h>
#include<stdint.h>
#include<stdlib.h>
// #include<stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include<fcntl.h>

bool do_system(const char *command);

bool do_exec(int count, ...);

bool do_exec_redirect(const char *outputfile, int count, ...);
