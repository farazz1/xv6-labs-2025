#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

// CPU-intensive process that will get demoted
int main(int argc, char *argv[]) {
    int pid = getpid();
    printf("CPU Hog PID %d: Starting CPU-intensive work\n", pid);
    
    int iterations = 20000000;  // Reduced from 100M to 20M
    int result = 0;
    
    // Heavy CPU computation - will use full time quanta
    for (int i = 0; i < iterations; i++) {
        result += i * i;
        if (i % 5000000 == 0) {
            printf("CPU Hog PID %d: Progress %d/4\n", pid, i / 5000000);
        }
    }
    
    printf("CPU Hog PID %d: Finished with result %d\n", pid, result);
    exit(0);
}
