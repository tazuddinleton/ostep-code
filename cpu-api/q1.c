

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  int x = 10;
  printf("before fork x: %d, pid: %d\n", x, getpid());

  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(EXIT_FAILURE);
  }

  if (rc == 0) {
    // child process

    printf("child process x before inc: %d, pid: %d\n", x, getpid());
    x += 1;
    printf("child process x after inc: %d, pid: %d\n", x, getpid());
  } else {
    // parent process

    int wait_rc = wait(NULL);
    printf("parent process x: %d, pid: %d, wait_rc: %d\n", x, getpid(),
           wait_rc);
  }

  return EXIT_SUCCESS;
}
