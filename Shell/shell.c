#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    pid_t id;
    unsigned char cmd[100];
   while(1)
   {
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
    if(cmd == 'exit')
    {
    	exit(0);
    	}
    	    }
    return 0;
}
