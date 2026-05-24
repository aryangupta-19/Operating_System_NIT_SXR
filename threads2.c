#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void* myFunc(void* arg){
    printf("Now I am in thread/...!");
    for(int i = 0; i<5; i++){
        printf("%d\n", i);
        sleep(1);
    }

    return NULL;    // returning null as it is not int type funtion 
}

int main(){
    pthread_t t1;
    pthread_create(&t1, NULL, myFunc, NULL);    // created thread 
    pthread_join(t1, NULL);     // wait for  t1 

    printf("Inside main thread...!");
    
    for(int i = 20; i<25; i++){
        printf("%d\n", i);
        sleep(1);
    }

    return 0;
}