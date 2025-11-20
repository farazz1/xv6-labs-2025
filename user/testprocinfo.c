#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(void) {
  struct procinfo info;
  
  printf("=== Testing getprocinfo System Call ===\n");
  
  // Test with current process
  if(getprocinfo(&info, getpid()) == 0) {
    printf("✅ Success! Got process info:\n");
    printf("PID: %d\n", info.pid);
    printf("Process Name: %s\n", info.name);
    printf("State: %d\n", info.state);
    printf("Memory Size: %d bytes\n", (int)info.size);
  } else {
    printf("❌ Failed to get process info\n");
  }
  
  // Test with invalid PID
  printf("\nTesting with invalid PID...\n");
  if(getprocinfo(&info, 9999) < 0) {
    printf("✅ Correctly failed for invalid PID\n");
  }
  
  exit(0);
}
