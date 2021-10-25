//Author : Kundan Kumar 
//Roll No: 207929
//Assignment 05 Solution
#include<iostream>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>


using namespace std;

#define size_max 5 
#define size 5

sem_t empty;
sem_t full;
int in = 0;
int out = 0;
int buffer[size];
pthread_mutex_t mutex;

void *producer(void *producer_num){   
    int item;
    for(int i = 0; i< size_max; i++){
    	item = rand()/10;
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        buffer[in] = item;
        cout<<"Producer : "<<*((int *)producer_num)<<" Inserted item "<<buffer[in]<<" at "<<in<<endl;
        in = (in+1)%size;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
    return 0; 
}

void *consumer(void *consumer_num){   
    for(int i = 0; i < size_max; i++) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        int item = buffer[out];
        cout<<"Consumer : "<<*((int *)consumer_num)<<" Removed item "<<item<< " from "<<out<<endl;
        out = (out+1)%size;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
    return 0; 
}


int main()
{   
    pthread_t Producer[3],Consumer[3];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty,0,size);
    sem_init(&full,0,0);

    int a[3] = {1,2,3}; 

    for(int i = 0; i < 3; i++) {
        pthread_create(&Producer[i], NULL, producer, &a[i]);
    }
    for(int i = 0; i < 3; i++) {
        pthread_create(&Consumer[i], NULL, consumer, &a[i]);
    }

    for(int i = 0; i < 3; i++) {
        pthread_join(Producer[i], NULL);
    }
    for(int i = 0; i < 3; i++) {
        pthread_join(Consumer[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
    
}