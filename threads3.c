#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void* myFunc(void* arg){
    printf("Inside thread\n");
    int* x = (int*) arg;
    int sum = x[0] + x[1];
    printf("Sum is %d\n", sum);
    pthread_exit("Sum Calculated");
}

int main(){
    pthread_t t1;
    int num[2] = {3,5};     // here we will pass num as argument to out threadFunctio i.e muFunc
    pthread_create(&t1, NULL, myFunc, (void*) num);         // note down the method of passing is {deconstruction} method
    void* result;
    pthread_join(t1, &result);      // first argument is thread and second argument is usally NULL but actually it 
    // to recieve the returned value from thread that's why here we used it to get returned value from the myFunc

    printf("Inside the Main process...!");
    printf("Thread returned %s\n", (char*) result);

    return 0;
}

// 1) declare thread variable and id 
// (if using arg in next step then declare it here)
// 2) create thread -> &t1, NULL, myFuync, (void*) arg or NULL
// (declare if you want send reciever here)
// 3) join thread to make it wait (threadName, NULL or (recevier to recieve the returned value from thread functio ))
// 4)end with printing sum you recieved as result 