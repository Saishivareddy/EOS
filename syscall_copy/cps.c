#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argv[], char *argc[])
{
    int fdr,fdw;
    size_t in;
    unsigned char buff[BUFSIZ];

    fdr=open(argc[1],O_RDWR);
    if(-1==fdr)
    {
        perror("Error opening Source file\n");
        return -1;
    }
    else
    {   
        while(1)
        {
            in=read(fdr, buff,sizeof(buff));
        
        if (0 ==in)
        {
            break;
        }
        else
        {
            perror("Copying failed\n");
        }
        }
    }

    fdw=open(argc[2], O_CREAT|O_RDWR);
    if(-1==fdr)
    {
        perror("Error opening Destinaton file\n");
        return -2;
    }
    else
    {
        while(1)
        {
            write(fdw,buff,in);
            if(-1==fdr)
            {
                perror("Error copying into Destinaton file\n");
                break;
                return -2;
            }
            else if(0 == fdw)
            {
                printf("Copied data into %s\n", argc[2]);
                break;
            }
        }
        

    }
    close(fdr);
    close(fdw);
    
    return 0;
}