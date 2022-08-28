#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{

  /*
    For this problem we need 3 variables:
    1) A variable that help us to check the actual status of each process.
    2) A pointer variable that will store the command-line
    3) A variable that will store the pid when the fork() is called.

    NOTE: the pointer variable works as a array.
  */
  int status_process;
  char* args[3];

  args[0] = "/bin/ls";
  args[1] = "-l";
  args[2] = NULL;

  int pid = fork();

  /*
    Execv(args[0],args) will be in charge of executing the ls -l line command
    wait() will be in charge of waiting for the next child process according
    to the actual status process that is running at that moment. 
  */

  if(pid < 0){
    printf("There was an error! Try again! \n");
  }else if(pid == 0){
    execv(args[0],args);
  }else{
    wait(&status_process);
  }

 return 0;
}
