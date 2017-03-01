


#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#define NUM_PROC 3

int main (void) {
	int pid;
	int i,recurso;
	for (i=0; i < NUM_PROC; i++){
		if ((pid=fork()) < 0){
			printf("Error al emplear fork\n");
			exit(EXIT_FAILURE);
		}else if (pid == 0){
			printf("HIJO  %d\tPadre: %d\n", getpid(), getppid());     
		}else{
			printf ("PADRE %d\n", getpid());
		}
		
	}
	
	exit(EXIT_SUCCESS);
}
