#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t id;
    printf("Before fork Process ID is %d and Parent PID is %d\n", getpid(),getppid());
    id = fork();
    printf("After fork Process ID is %d and Parent PID is %d\n", getpid(),getppid());
    return 0;
}
