#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void main(){
	DIR *d;
	struct dirent *de;
	d=opendir(".");
	while(de=readdir(d))
	printf("%s\n",de->d_name);
	closedir(d);
}
