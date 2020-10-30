#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>

int counter=0,in=0,out=0;
void * consumer();
void * producer();
void wait(int*);
void signal(int*);
pthread_t tid[2];
int *buffer;
int mutex=1;

int main()
{
        buffer=(int*)calloc(200,sizeof(int));
        pthread_create(&tid[0],NULL,producer,NULL);
        sleep(1);
        pthread_create(&tid[1],NULL,consumer,NULL);
        pthread_join(tid[0],NULL);
        pthread_join(tid[1],NULL);
        printf("\nExit the program\n");
        exit(0);
}
void * producer()    
{
    int item=1;
    while(1){
    wait(&mutex);
    buffer[in]=item;
    counter++;
    printf("Producer: produced item %d ,no of items in buffer:%d\n",item,counter);
    in=in+1;
    item++;
    signal(&mutex);
    sleep(rand()%10);
    }
}
void * consumer()

{     
    while(1){
    wait(&mutex);
    int a=buffer[out];
    counter--;
    printf("Consumer: consumed item %d ,no of items in buffer:%d\n",a,counter);
    out=out+1;
    signal(&mutex);
    sleep(rand()%10);
    }
}
void wait(int* mutex){
  while(*mutex<=0);
  *mutex--;
}
void signal(int* mutex){
  *mutex++;
}

