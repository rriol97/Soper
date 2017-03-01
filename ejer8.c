#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

/*/home/alumnos/e340216/Desktop/workspace*/

int main(int argc, char*argv[]) {
	int i, pid = 1, retorno,status;
	char *entrada[2];

	if(argc < 1) {
		printf("Error en los parametros de entrada\n");
		return 1;
	}

	for (i = 0; i < argc  ; i++){
		
		if ( pid < 0){

			printf("Error en el fork");
		}

		else if (pid > 0){

			pid = fork ();
		}

		else {
			entrada [0] = argv[i+1];
			entrada [1] = NULL;

			if(!strcmp(argv[argc-1], "-l")) {
				return execl(argv[i], entrada[0]);
			}
			else if(!strcmp(argv[argc-1], "-lp")) {
				return execlp(argv[i], entrada[0]);
			}
			else if(!strcmp(argv[argc-1], "-v")) {
				return execv(argv[i], entrada);
			}
			else if(!strcmp(argv[argc-1], "-vp")) {
				return execvp(argv[i], entrada);
			}
			printf ("\n");
		}
	}

	
	for (i = 0;i < argc;i++){
		wait(&status);
	}	
	
	return 0;
}

