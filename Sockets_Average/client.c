#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<linux/in.h>

int cfd;
struct sockaddr_in saddr;
int a;
float avg;
int main(int argc, char const *argv[])
{
    cfd = socket(AF_INET,SOCK_STREAM,0);

    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = inet_addr("10.0.0.22");
    saddr.sin_port = htons(1412);

    connect(cfd,(const struct sockaddr *)&saddr,sizeof(saddr));
    for(int i=0;i<10;i++)
    {
        printf("Enter number %d: ",i);
        scanf("%d",&a);
        write(cfd, &a,sizeof(int));
    }
    
    read(cfd, &avg, sizeof(float));

    printf("Average from server is %f\n", avg);

    close(cfd);

    return 0;
}

