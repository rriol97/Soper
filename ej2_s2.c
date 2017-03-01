

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (){
	int x,y,status,options;
	pid_t p1;
	p1 = fork();
	x = 3;
	y = 5;

	if (p1==0){
		printf ("%d\n", x-y);
		printf("hijo: %d\n", getpid());
		printf("padre: %d\n", getppid());
		exit (EXIT_SUCCESS);
	} 

	if (p1>0){
		waitpid(p1, &status, 0);

		/*wait (&status);*/
		printf ("%d\n", x+y);
		printf("abuelo: %d\n", getppid());
		printf("padre: %d\n", getpid());
		
	}
	return 1;
} 