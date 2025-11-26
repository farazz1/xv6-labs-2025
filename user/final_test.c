#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main() {
    printf("=== Final MLFQ Test ===\n");
    
    int cpu_pid, io_pid;
    
    // Start CPU-bound process
    if((cpu_pid = fork()) == 0) {
        printf("CPU-bound (PID %d) starting in Q0\n", getpid());
        for(int i = 0; i < 100000000; i++) {
            // CPU work
        }
        printf("CPU-bound finished\n");
        exit(0);
    }
    
    // Start I/O-bound process  
    if((io_pid = fork()) == 0) {
        printf("I/O-bound (PID %d) starting in Q0\n", getpid());
        for(int i = 0; i < 5; i++) {
            printf("I/O-bound: working %d/5\n", i);
            pause(20);
        }
        printf("I/O-bound finished\n");
        exit(0);
    }
    
    wait(0);
    wait(0);
    printf("Final test completed\n");
    exit(0);
}
