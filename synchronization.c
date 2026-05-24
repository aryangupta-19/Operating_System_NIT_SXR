#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    pid_t q;
    q = fork(); // created a child process 

    if(q < 0){
        printf("Fork failed\n");
    }
    else if(q == 0){        // i am in child process 
        printf("Child Process Running\n");
        sleep(3);
        printf("Child Process Completed\n");
    }
    else{   // i am in parent process but q still holds child's pid 
        wait(NULL);     // asked parent process to wait for the completion of child process 
        printf("Parent Process Running After Child\n");
    }
    return 0;
}