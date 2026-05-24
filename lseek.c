#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
    int fd = open("text.txt", O_RDONLY);
    lseek(fd, 5, SEEK_CUR);

    char buff[31];
    int n = read(fd, buff, 30);
    buff[n] = '\0';

    printf("Data: %s\n", buff);
    close(fd);

    return 0;
}
