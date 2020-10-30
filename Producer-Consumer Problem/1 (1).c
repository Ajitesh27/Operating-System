#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int BUFFER_SIZE=6;
int counter=0,in=0,out=0;
void * consumer();
void * producer();
pthread_t tid[2];
int *buffer;

int main()
{
        buffer=(int*)calloc(BUFFER_SIZE,sizeof(int));
        pthread_create(&tid[0],NULL,producer,NULL);
        pthread_create(&tid[1],NULL,consumer,NULL);
        pthread_join(tid[0],NULL);
        pthread_join(tid[1],NULL);
        printf("\nExit the program\n");
        exit(0);
}
void *producer()    
{
    int item=1;
    while(1){
    while(counter==BUFFER_SIZE);
    buffer[in]=item;
    counter++;
    printf("Producer: produced item %d ,no of items in buffer : %d\n",item,counter);
    in=(in+1)%BUFFER_SIZE;
    
    item++;
    }
}
void *consumer()

{     
    while(1){
    while(counter==0);
    int a=buffer[out];
    counter--; 
    printf("Consumer: consumed item %d ,no of items in buffer: %d\n",a,counter);
    out=(out+1)%BUFFER_SIZE;
     
    }
}




