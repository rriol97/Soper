#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
	int pid, i = 0;
	int status;
	char* cadena = NULL;

		
	cadena = (char *)malloc(80*sizeof(char));
	if(!cadena)
		return 1;

	pid = fork();
	if(pid < 0) { /*Error*/
		printf("Error en fork");
		return 1;
	}
	else if(pid == 0) { /*Hijo*/
		printf("Proceso 1: %d\t", getpid());

		printf("Introduzaca un nombre: ");
		fscanf(stdin, "%s", cadena);
		free(cadena);
	}
	else { /*Padre*/
		printf("Proceso 2: %d\t", getpid());
		free(cadena);
	}
	wait(&status);
	
	return 0;	
}
