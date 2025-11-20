#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

// Process that mixes CPU and I/O work
int main(int argc, char *argv[]) {
    int pid = getpid();
    printf("Mixed Workload PID %d: Starting mixed work\n", pid);
    
    for (int cycle = 0; cycle < 5; cycle++) {
        printf("Mixed PID %d: Cycle %d - Starting CPU phase\n", pid, cycle);
        
        // Some CPU work
        int sum = 0;
        for (int i = 0; i < 5000000; i++) {
            sum += i;
        }
        
        printf("Mixed PID %d: Cycle %d - CPU done, now I/O phase\n", pid, cycle);
        
        // I/O phase - use pause instead of sleep
        pause(10);
        
        printf("Mixed PID %d: Cycle %d - I/O done\n", pid, cycle);
    }
    
    printf("Mixed PID %d: Finished\n", pid);
    exit(0);
}
