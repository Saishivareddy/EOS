#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 8192
int main(int argv[], char *argc[])
{
    unsigned char buff[MAX_SIZE];
    FILE *fpr, *fpw;
    size_t rd, wr;
    int size;

    fpr=fopen(argc[1],"r");

    if(fpr==NULL)
    {
        perror("Error opening source file\n");
        return -1;
    }

    fpw=fopen(argc[2], "w");

    if(fpw==0)
    {
        perror("Error opening destination file\n");
        return -1;
    }
    size =atoi(argc[1]);
    if (size > MAX_SIZE)
    {
        perror("File size exceeded\n");
        return -1;
    }
    while (1)
    {
        rd=fread(buff,1,MAX_SIZE,fpr);
        wr=fwrite(buff,1,rd,fpw);
        if(rd==0)
        {
            break;
        }
    }
    fclose(fpr);
    fclose(fpw);
    printf("Copied data into Destination file\n");
    return 0;
}