#include "fork.h"
int main()
{
    pid_t id;
    printf("pid is %d\n", getpid());
    id = fork();
    printf("pid is %d\n", getpid());
    return 0;

}
