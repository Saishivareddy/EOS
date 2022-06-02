#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_SIZE 8192

int main(int argv[], char *argc[])
{
    int fdr,fdw;
    int size;
    size_t rd,wr;
    unsigned char buff[MAX_SIZE];

    fdr=open(argc[1],O_RDONLY);
    if(-1==fdr)
    {
        perror("Error opening Source file\n");
        return -1;
    }
    fdw=open(argc[2], O_CREAT|O_WRONLY, 0777);
    if(-1==fdr)
    {
        perror("Error opening Destinaton file\n");
        return -1;
    }
    size =atoi(argc[1]);
    if (size > MAX_SIZE)
    {
        perror("File size exceeded\n");
        return -1;
    }
    while(1)
    {
        rd=read(fdr, buff,MAX_SIZE);
        
        if (0 ==rd)
        {
            break;
        }
        wr=write(fdw,buff,rd); 

        if (0 ==wr)
        {
            break;
        }  
    }
    close(fdr);
    close(fdw);
    printf("Copied data into %s\n", argc[2]);
    return 0;
}