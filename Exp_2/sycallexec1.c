#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void main(){
	char*args[]={"./EXEC",NULL};
	execvp(args[0],args);
	printf("Bye");
}
