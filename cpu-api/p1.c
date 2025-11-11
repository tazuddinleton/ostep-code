#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  printf("Hello (pid: %d)\n", (int)getpid());

  int rc = fork();

  if (rc < 0) {
    // fork failed
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    // child (new process)
    printf("child (pid: %d) \n", (int)getpid());
  } else {
    // parent goes doen this path (main)
    printf("parent of %d (pid: %d) \n", rc, getpid());
  }

  return 0;
}
