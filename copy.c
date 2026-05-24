// copying data from one file to another 
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
        // open() -> file name + permission     ---- returns fd 
        // read() -> fd , buffer (to contain data), no. of bytes reading  ----- returns no. of bytes actually read or taken input depending on fd 
        // write() -> fd, buffer, no. of bytes writting (use n here exact bytes)    ------ no. of bytes actually written
    int fd1 = open("test.txt", O_RDONLY);
    char buff[50];
    int n = read(fd1, buff, 30);
    int fd2 = open("target.txt", O_CREAT | O_WRONLY, 0721);
    write(fd2, buff, n);

    close(fd2);
    close(fd1);
    return 0;
}