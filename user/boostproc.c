#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: boostproc <pid>\n");
        exit(1);
    }
    
    int pid = atoi(argv[1]);
    if(boostproc(pid) < 0) {
        printf("boostproc: failed to boost PID %d\n", pid);
        exit(1);
    }
    
    exit(0);
}
