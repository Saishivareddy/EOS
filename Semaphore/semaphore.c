#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int count =0;
sem_t count_me;
void *incThread(void *arg)
{
    while(1)
    {
        sem_wait(&count_me);
        count++;
        printf("Inc Thread: %d\n",count);
        sem_post(&count_me);
    }
}
void *decThread(void *arg)
{
    while(1)
    {
        sem_wait(&count_me);
        count--;
        printf("Dec Thread: %d\n",count);
        sem_post(&count_me);
    }
}
int main()
{
    pthread_t inc,dec;
    sem_init(&count_me, 0, 1);
    pthread_create(&inc,NULL,incThread,NULL);
    pthread_create(&dec,NULL,decThread,NULL);
    pthread_join(inc,NULL);
    pthread_join(dec,NULL);
    sem_destroy(&count_me);
    return 0;
}