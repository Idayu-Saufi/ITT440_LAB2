#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


void childTask() {	//function for childTask
  printf("\nGood Day, What should I call you? \n");
}

void parentTask() {	//function for parentTask
  printf("Job is done \n");
}

int main() {
  for(int i = 1; i < 5; i++) {	//to loop 4-child process
    pid_t pid = fork();	//using fork()
    char name[20];


    if(pid == 0) {
     childTask();
     printf("Name: ");
     scanf("%s",name);	//ask user to enter name
     printf("\nHi! glad to know you, %s.\n",name);	//display name given by user
     printf("\nChild process => PPID=%d, PID=%d\n", getppid(), getpid());
     exit(0);
    }
    else {
     printf("Parent process => PID=%d\n", getpid());
     printf("Waiting for child processes to finish... \n\n");
     wait(NULL);	//using wait()
    } 
   }

   parentTask();	//to print out Job is done at the end of process
   return EXIT_SUCCESS;
  }
