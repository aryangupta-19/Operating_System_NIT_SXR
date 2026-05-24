// Program to create a thread, thread prints 0 - 4 while the main process prints 20 - 24
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

// Thread function
void* myFunc(void* arg) {

    printf("Inside thread\n");
    for(int i = 0; i < 5; i++) {
        printf("%d\n", i);
        // sleep(1);
    }

    return NULL;
}

int main() {
    pthread_t t1;

    // Create thread
    pthread_create(&t1, NULL, myFunc, NULL);
    printf("Inside main program\n");
    for(int j = 20; j < 25; j++) {
        printf("%d\n", j);
        sleep(1);
    }

    // Wait for thread to finish
    pthread_join(t1, NULL);
    return 0;
}


// #include<stdio.h>
// #include<pthread.h>

// void* myFunc(void* arg){
//     printf("Aryan's Thread function...!");
// }

// int main(){
//    pthread_t t1;
//    pthread_create(&t1, NULL, myFunc, NULL);

//    printf("Aryan's Main function is running...\n!");
//    return 0;
// }