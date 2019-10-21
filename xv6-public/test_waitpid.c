#include "types.h"
#include "stat.h"
#include "user.h"
int main(int argc, char * argv[]) {
  int count = 1;
  int pid = 0, pid2 = 0;
  if ( (pid = fork()) ) {
    count = count + 2;
    printf(“%d ”, count);
  }
  if (count == 1) {
    count++;
    pid2 = fork();
    printf(“%d ”, count);
  }
  if (pid2) {
    waitpid(pid2, NULL, 0);
    count = count * 2;
    printf(“%d  ”, count);
  }
  exit();
}
