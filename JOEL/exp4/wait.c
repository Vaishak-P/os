#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
void main(){
    int pid,status;
    pid = fork();
    if(pid == 1){
        printf("fork faild\n");
        _exit(1);
    }else if(pid ==! 0){
        printf("child here! %d\n",pid);
    }else{
        wait(&status);
        printf("WEll Done Child %d\n",pid);
    }
}