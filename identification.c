#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
    pid_t q;
    printf("Before fork \n");
    q = fork();     // fork return child's pid 

    if(q < 0) printf("Error..!!!");
    else if(q == 0){        // q == 0 means I am child , >0 means i am parent but still returns pid of child
        printf("I am child having pid as %d\n", getpid());
        printf("My parent's pid is %d\n", getppid());
    }else{
        printf("My child's pid is %d\n", q);
        printf("I am parent having id %d\n", getpid());
    }
    
    printf("common\n"); 
    return 0;
}