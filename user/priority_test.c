#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

// Simple test to demonstrate priority changes
int main(int argc, char *argv[]) {
    int pid = getpid();
    printf("Priority Test PID %d: Starting\n", pid);
    
    printf("Phase 1: CPU-intensive (should demote)\n");
    for (int i = 0; i < 100000000; i++) {
        // CPU work
        if (i % 20000000 == 0) {
            printf("  PID %d: CPU work %d/5\n", pid, i / 20000000);
        }
    }
    
    printf("Phase 2: I/O intensive (may promote)\n");
    for (int i = 0; i < 5; i++) {
        printf("  PID %d: I/O cycle %d/5\n", pid, i);
        pause(10);  // Use pause instead of sleep
    }
    
    printf("Priority Test PID %d: Finished\n", pid);
    exit(0);
}
