#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<linux/in.h>

int a = 0;
int sum = 0;
float avg = 0;
int sfd, cfd;
int len;

struct sockaddr_in saddr;
struct sockaddr_in caddr;


int main(int argc, char const *argv[])
{
    sfd= socket(AF_INET, SOCK_STREAM, 0);

    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = inet_addr("10.0.0.22");
    saddr.sin_port = htons(1412);

    bind(sfd, (const struct sockaddr *)&saddr, sizeof(saddr));
    listen(sfd, 2);

    len = sizeof(struct sockaddr_in);
    cfd = accept(sfd, (struct sockaddr_in *)&saddr, &len);

    for (int i = 0; i < 10; i++)
    {
        read(cfd, &a, sizeof(int));
        sum = sum + a;
    }
    avg = sum/10;
    
    printf("Average of numbers is %f\n", avg);

    write(cfd, &avg, sizeof(float));

    close(cfd);
    close(sfd);

    return 0;
}
