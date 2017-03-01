#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 10

int main() {
	int pid, i = 0;
	int status;

	
	for(i=0; (pid = fork() == 0) && i < MAX; i++) {
		if(pid < 0) {
			printf("Error en el fork");
		}
		printf("Proceso: %d\t", getpid());
		printf("Padre: %d\n", getppid());
	}
	wait(&status);
	
	return 0;	
}
