#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    pid_t id;
    unsigned char cmd[100];
    printf("CDAC Shell ##: ");
    scanf("%s",cmd);
    id =fork();
    if(id==0)
    {
        execlp(cmd,cmd,NULL);
    }
    else
    {    
        wait(NULL);
    }
    return 0;
}