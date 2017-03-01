#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#define NUM_PROC 3

int main (void){

	int pid;
	int i;
	int status;
	for (i=0; i < NUM_PROC; i++){
		if ((pid=fork()) <0 ){

			printf("Error haciendo fork\n");
			exit(EXIT_FAILURE);

		}else if (pid ==0){

			printf("HIJO  %d\t%d\t%d\n", i, getpid(), getppid()); 

		} else {
			printf ("PADRE %d\t%d\n", i, getpid());
		}
	}
	wait(&status);
	exit(EXIT_SUCCESS);

}