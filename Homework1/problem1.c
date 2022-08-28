#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
  printf("\n");

  //The following code will be in charge to solve problem 1 from the book.

  // First, we declare variable "dummy" with a value of 100.
  // This will help us to check if there are changes in this variable.

  int dummy = 100;

  pid_t pid = fork();

  if(pid < 0){
      printf("There was a mistake. Child creation was not successful. \n");
   }
   else if(pid == 0){
      printf("Child creation completed! 50 will be added to dummy \n");
      dummy = dummy + 50;
      printf("Actual value of 'dummy':%d \n",dummy);
   }
   else{
      printf("Parent detected! 100 will be added to dummy \n");
      dummy = dummy + 100;
      printf("Actual value of 'dummy':%d \n",dummy);
      wait(NULL);
   }
  return 0;
}
