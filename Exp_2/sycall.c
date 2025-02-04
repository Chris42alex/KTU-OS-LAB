#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void main(){
	pid_t p = fork();
	printf("pid = %d\n",p);

	if(p==0){
		printf("It is the child process\n");
		printf("Child id %d\n",getpid());
		printf("Parent id %d\n",getppid());

	}
	else if(p>0){
		printf("It is the parent process\n");
		printf("Parent id %d\n",getpid());
		printf("Child id %d\n",p);
	}

	else {
		printf("Terminating");
	}
exit(2);
}	
