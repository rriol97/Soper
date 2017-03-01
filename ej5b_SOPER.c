#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 4

int main() {
	int pid = 1, i = 0;
	int status;

	
	for(i=0; i < MAX; i++) {
		if (pid > 0){
			pid = fork ();
		}

	}

	if (pid == 0){
		printf("Proceso: %d\t", getpid());
		printf("Padre: %d\n", getppid());
	}

	for (i = 0;i<MAX;i++){
		wait(&status);
	}	
	
	return 0;	
}





int metodo(char* exe, char* flag[]) {
	if(!strcmp(flag, "-l")) {
		return execl(exe, flag[0]);
	}
	else if(!strcmp(flag, "-lp")) {
		return execlp(exe, flag[0]);
	}
	else if(!strcmp(flag, "-v")) {
		return execv(exe, flag);
	}
	else if(!strcmp(flag, "-vp")) {
		return execvp(exe, flag);
	}



}