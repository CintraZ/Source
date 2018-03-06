#include <stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int main(int argc, char *argv[])
{
    if(argc != 3) printf("Error!\n");
    else
    {
        int file1,file2;
        if((file1 = open(argv[1],O_RDONLY)) == -1)
        {
            printf("file open failed!");
            return 0;
        }
        if((file2 = open(argv[2],O_RDWR|O_CREAT,0666)) == -1)
        {
            printf("file open failed!");
            return 0;
        }
        int readsize = 1;
        char buffer[MAX_SIZE];
        do
        {
            readsize = read(file1,buffer,MAX_SIZE);
            write(file2,buffer,readsize);
        }
        while(readsize);
        close(file1);
        close(file2);
    }
    return 0;    
}