#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main() {
    printf("Sleep test PID %d: Running for 30 seconds\n", getpid());
    for(int i = 0; i < 6; i++) {
        printf("Sleep test: %d/6 cycles\n", i);
        pause(50);  // Sleep for 50 ticks
    }
    printf("Sleep test completed\n");
    exit(0);
}
