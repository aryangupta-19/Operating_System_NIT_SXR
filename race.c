#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

int shared = 1; 

void* func1(void* arg){
    int x = shared;
    printf("Thread1 accessing the shared variable's value: %d\n", x);
    x++;
    printf("Local update by thread1 : %d\n", x);
    sleep(1);
    shared = x;
    printf("Shared variable updated by thread1: %d\n", shared);
    return NULL;
}

void* func2(void* arg){
    int y = shared;
    printf("Thread2 accessing the shared variable's value: %d\n", y);
    y--;
    printf("Local update by thread1 : %d\n", y);
    sleep(1);
    shared = y;
    printf("Shared variable updated by thread2: %d\n", shared);
    return NULL;
}

int main(){
    pthread_t t1, t2;
    pthread_create(&t1, NULL, func1, NULL);
    pthread_create(&t2, NULL, func2, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final value of shared variable is %d\n", shared);
    return 0;
}