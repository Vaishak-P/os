#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
void main(){
    pid_t childid,parentid;
    childid=getpid();
    parentid = getpid();
    printf("child %d\n",childid);
    printf("parentid %d\n",parentid);
}
