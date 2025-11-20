#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

// I/O bound process that yields frequently (should stay in high priority)
int main(int argc, char *argv[]) {
    int pid = getpid();
    printf("I/O Bound PID %d: Starting I/O simulation\n", pid);
    
    for (int i = 0; i < 10; i++) {
        printf("I/O Bound PID %d: Cycle %d - Doing I/O work\n", pid, i);
        
        // Simulate I/O wait by pausing (yielding CPU)
        pause(5);  // Use pause system call instead of sleep
        
        printf("I/O Bound PID %d: Cycle %d - I/O complete\n", pid, i);
    }
    
    printf("I/O Bound PID %d: Finished\n", pid);
    exit(0);
}
