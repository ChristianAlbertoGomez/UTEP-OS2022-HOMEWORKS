#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
   //First, we must call fork() to start doing all the processes
   int pid = fork();
   int x = 0; //x will help us to check if there are changes in the processes

   if(pid < 0){
       printf("There was an error! Try again! \n");
   }else if(pid == 0){
       //Remember that 0 means we are in the child process

       printf("Hello! I'm child process. Here is my id:%d \n",(int)getpid());
   }else{
       //Here we are in the parent/main process if pid > 0.

       // Also, here we are going to produce a delay for the exercise.
       for(int i = 0; i < 10000000; i++){
         x = i;
       }
       printf("Goodbye! Atte: Parent of %d \n",pid);
   }
  return 0;
}
