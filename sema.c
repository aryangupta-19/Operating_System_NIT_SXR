// semaphores -> sema_post(){increments semaphore value}, sema_init(), sema_wait() {decrements semaphore value}
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

sem_t mutex;
int shared = 0;

// void* semaphore(void* arg){

//     sem_wait(&mutex);
//     shared++;
//     printf("Shared value: %d\n", shared);
//     sem_post(&mutex);

//     return NULL;
// }

void* func1(void* arg){
    int x = shared;

    sem_wait(&mutex);   // lock 

    sleep(1);
    x = shared;
    printf("Thread1 reads the value : %d\n", x);
    x++;
    printf("Local update by thread 1 : %d\n", x);
    shared = x;
    printf("Shared variable's value updated by thread1 : %d\n", shared);

    sem_post(&mutex); // unlock;

    return NULL;
}

void* func2(void* arg){
    int y = shared;

    sem_wait(&mutex);   // lock 

    sleep(1);
    y = shared;
    printf("Thread2 reads the value : %d\n", y);
    y--;
    printf("Local update by thread 1 : %d\n", y);
    sleep(1);
    shared = y;
    printf("Shared variable's value updated by thread2 : %d\n", shared);

    sem_post(&mutex); // unlock;

    return NULL;
}

int main(){

    pthread_t t1, t2;
    sem_init(&mutex, 0 , 1); // mutex - sema_name, shared process -> 0 means shared between threads of same process, init value
    pthread_create(&t1, NULL, func1, NULL);
    pthread_create(&t2, NULL, func2, NULL);
    // // sem_t mutex; // created a new semaphote variable mutex
    // sem_wait(&mutex); // lock operation 
    // sem_post(&mutex); // unlock operation 

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final value of shared variable : %d\n", shared);
    sem_destroy(&mutex);  // destrouying the semaphore

    return 0;
}
