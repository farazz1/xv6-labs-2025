#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main() {
    printf("Long test PID %d: Starting\n", getpid());
    
    // Much longer computation to see multiple time slices
    for(int phase = 0; phase < 10; phase++) {
        printf("Phase %d/10: Starting CPU work\n", phase);
        int result = 0;
        for(int i = 0; i < 50000000; i++) {  // 50M iterations
            result += i * i;
        }
        printf("Phase %d/10: CPU work done\n", phase);
    }
    
    printf("Long test completed\n");
    exit(0);
}
