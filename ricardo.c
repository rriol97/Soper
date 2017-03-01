#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX 4
#define MAXCHAR 100



int main(void) {
int fd[2], nbytes, pipe_status, op1, op2,status,operando1,operando2,id;
int fd1[2];
pid_t childpid;
char string[MAXCHAR];
char readbuffer[80];
char buffer[80];
char *token;
char hijo[MAXCHAR]= "";


printf ("Introduzca el primer operando: ");
scanf ("%d", &op1);

printf ("Introduzca el segundo operando: ");
scanf ("%d", &op2);

sprintf (string, "%d,%d.", op1,op2);




pipe_status=pipe(fd);

if(pipe_status==-1) {

	perror("Error creando la tuberia\n");
	exit(EXIT_FAILURE);
}

pipe_status = pipe(fd1);

if(pipe_status==-1) {

	perror("Error creando la tuberia\n");
	exit(EXIT_FAILURE);
}

if((childpid = fork()) == -1){

	perror("fork");
	exit(EXIT_FAILURE);

}

if(childpid > 0){

	close(fd[0]);
	write(fd[1], string, strlen(string));

	wait(&status);

	close (fd1[1]);
	nbytes = read(fd[0], buffer, sizeof(buffer));
	printf ("%s", buffer);

} else{

	close(fd[1]);

	nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
	token = strtok(readbuffer,",");
	operando1 = atoi (token);

	token = strtok (NULL, ".");
	operando2 = atoi (token);

	id = getpid();

	sprintf (hijo, "%d,%d", id, operando1+operando2);
	printf ("%s", hijo);
	close (fd1[0]);
	write (fd1[1],hijo,strlen(hijo));
	exit(0);
}
return(0);
}