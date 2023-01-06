#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
void main(){
	pid_t pid;
	pid = fork();
	if(pid == 0)
		printf("\n I'm a child process %d\n",pid);
	else if(pid>0)
		printf("\n I'm the parent process.Mychild pid is %d\n",pid);
	else
		perror("error in fork");
}
