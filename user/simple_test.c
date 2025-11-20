// Create a simple test: user/simple_test.c
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main() {
    printf("Simple test: PID %d\n", getpid());
    for(int i = 0; i < 1000000; i++) {
        // Some work
    }
    printf("Simple test completed\n");
    exit(0);
}
