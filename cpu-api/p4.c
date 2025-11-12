#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  printf("hello (%d)\n", getpid());
  int rc = fork();

  if (rc < 0) {
    fprintf(stderr, "fork failed \n");
    exit(1);
  }

  if (rc == 0) {
    // child new process
    // redirect the standard output to a file
    close(STDOUT_FILENO);
    open("p4.output.txt", O_CREAT | O_WRONLY | O_TRUNC | S_IRWXU);
    printf("child (pid: %d)\n", getpid());

    char *myargs[3];
    myargs[0] = strdup("wc");   // arg: input file
    myargs[1] = strdup("p4.c"); // arg: input file
    myargs[2] = NULL;
    execvp(myargs[0], myargs); // runs the word count
    printf("this shouldn't print out");
  } else {
    // parent goes down this path
    int rc_wait = wait(NULL);
    printf("parent of %d (rc_wait: %d) (pid: %d)", rc, rc_wait, getpid());
  }

  return 0;
}
