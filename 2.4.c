#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


void childTask() {
  printf("\nGood Day, What should I call you? \n");
}

void parentTask() {
  printf("Job is done \n");
}

int main() {
  for(int i = 1; i < 5; i++) {
    pid_t pid = fork();
    char name[20];


    if(pid == 0) {
     childTask();
     printf("Name: ");
     fgets(name, sizeof(name), stdin);
     printf("\nHi! nice to meet you, %s",name);
     printf("\nChild process => PPID=%d, PID=%d\n", getppid(), getpid());
     exit(0);
    }
    else {
     printf("Parent process => PID=%d\n", getpid());
     printf("Waiting for child processes to finish... \n\n");
     wait(NULL);
    } 
   }

   parentTask();
   return EXIT_SUCCESS;
  }
