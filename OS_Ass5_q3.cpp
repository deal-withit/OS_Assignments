//Author : Kundan Kumar
//Roll : 207929
//Assignment 05, Q.No 03 Solution
#include<iostream> 
#include<pthread.h> 
#include<unistd.h> 
#include<semaphore.h> 
using namespace std; 
int temp=1; 
sem_t s;
void *thread_1(void *arg) 
{ 
   int x; 
   sem_wait(&s); 
   x=temp; 
   cout<<"First_thread reads the value of shared variable as : "<<x<<endl; 
   x++; 
   cout<<"Increment of shared variable by first_thread as : "<<x<<endl; 
   sleep(1); 
   temp=x; 
   cout<<"Value of shared variable updated by first_thread is : "<<temp<<endl; 
   sem_post(&s); 
   return 0; 
} 
void *thread_2(void *arg) 
{ 
   int y; 
   sem_wait(&s); 
   y=temp; 
   cout<<"second_thread reads the value of shared variable as : "<<y<<endl; 
   y--; 
   cout<<"Decrement of shared variable by second_thread as : "<<y<<endl;
   sleep(1); 
   temp=y; 
   cout<<"Value of shared variable updated by second_thread is : "<<temp<<endl; 
   sem_post(&s); 
   return 0; 
 } 
 
 int main() { 

   sem_init(&s,0,1); 
   pthread_t first_thread; 
   pthread_t second_thread; 
   pthread_create(&first_thread, NULL, thread_1, NULL); 
   pthread_create(&second_thread, NULL, thread_2, NULL); 
   pthread_join(first_thread, NULL); 
   pthread_join(second_thread,NULL); 
   cout<<"\n\nFinal value of temp is : "<<temp<<endl; 
   return 0; 
 } 