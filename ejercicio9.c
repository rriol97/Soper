#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX 4
#define MAXCHAR 1000

int main(){

	int i, op1, op2,nbytes,operando1,operando2,id,status;
	int pid = 1;
	int fd[2], pipe_status;
	int fd1[2];
	char string[MAXCHAR] = "";
	char buffer[MAXCHAR];
	char *token;
	char resultado[MAXCHAR]="";
	char final[MAXCHAR];

	printf ("Introduzca el primer operando: ");
	scanf ("%d", &op1);

	printf ("Introduzca el segundo operando: ");
	scanf ("%d", &op2);

	sprintf (string, "%d,%d", op1,op2);



	for (i = 0; i < MAX; i++){

		pipe_status = pipe (fd);


		if (pipe_status == -1){
			perror("Error creando la tuberia\n");
			exit(EXIT_FAILURE);
		}

		pipe_status = pipe (fd1);
	

		if (pipe_status == -1){
			perror("Error creando la tuberia\n");
			exit(EXIT_FAILURE);
		}

		if (pid < 0){
			return 0;
		}

		else if (pid > 0){
			pid = fork();

			if (pid > 0){

				close(fd[0]);
				write(fd[1], string, strlen(string));

				wait(&status);

				close (fd1[1]);
				nbytes = read(fd1[0], final, sizeof(final));
				printf ("%s", final);

			} else{

				close(fd[1]);
				nbytes = read (fd[0], buffer, sizeof(buffer));

				token = strtok(buffer,",");
				operando1 = atoi (token);

				token = strtok (NULL, "/0");
				operando2 = atoi (token);

				id = getpid();
			

				if (i == 0){
					sprintf (resultado, "\nDatos enviados a tavés e la tubería por el proceso %d .Operando 1: %d. Operando 2: %d. Suma: %d\n", id, operando1, operando2, operando1+operando2);
				}
				else if (i == 1){
					sprintf (resultado, "\nDatos enviados a tavés e la tubería por el proceso %d .Operando 1: %d. Operando 2: %d. Resta: %d\n", id, operando1, operando2, operando1-operando2);
				}

				else if (i == 2){
					sprintf (resultado, "\nDatos enviados a tavés e la tubería por el proceso %d .Operando 1: %d. Operando 2: %d. Multiplicación: %d\n", id, operando1, operando2, operando1*operando2);
				}
				else {
					sprintf (resultado, "\nDatos enviados a tavés e la tubería por el proceso %d .Operando 1: %d. Operando 2: %d. División: %f\n", id, operando1, operando2, (double)operando1/(double)operando2);
				}

				close (fd1[0]);
				write (fd1[1], resultado, strlen(resultado));


				exit(EXIT_SUCCESS);


			}

		
		}

	}

	


	return 0;


}