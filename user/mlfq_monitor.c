#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

// Monitors process priority changes in MLFQ
int main(int argc, char *argv[]) {
    printf("=== MLFQ Scheduler Monitor ===\n");
    printf("This program monitors process behavior under MLFQ\n\n");
    
    int monitor_pid = getpid();
    printf("Monitor PID: %d\n", monitor_pid);
    
    // Fork child processes with different behaviors
    int cpu_child, io_child, mixed_child;
    
    if ((cpu_child = fork()) == 0) {
        // CPU hog child
        char *args[] = {"cpu_hog", 0};
        exec("cpu_hog", args);
        exit(0);
    }
    
    if ((io_child = fork()) == 0) {
        // I/O bound child  
        char *args[] = {"io_bound", 0};
        exec("io_bound", args);
        exit(0);
    }
    
    if ((mixed_child = fork()) == 0) {
        // Mixed workload child
        char *args[] = {"mixed_workload", 0};
        exec("mixed_workload", args);
        exit(0);
    }
    
    // Parent process monitors
    printf("Launched test processes:\n");
    printf("  CPU Hog: PID %d\n", cpu_child);
    printf("  I/O Bound: PID %d\n", io_child); 
    printf("  Mixed: PID %d\n", mixed_child);
    printf("\nMonitoring for 50 ticks...\n");
    
    // Monitor for a while - use pause instead of sleep
    for (int i = 0; i < 10; i++) {
        pause(5);  // Wait 5 ticks
        printf("Monitor: Tick %d - System running\n", i * 5);
    }
    
    printf("\nMonitor: Finished monitoring\n");
    
    // Wait for children
    wait(0);
    wait(0); 
    wait(0);
    
    printf("All test processes completed\n");
    exit(0);
}
