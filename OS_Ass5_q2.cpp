//Author : Kundan Kumar 
//Roll No: 207929
//Assignment 05, QNo. 02 Solution
#include<iostream> 
#include<pthread.h> 
#include<unistd.h> 
using namespace std; 
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER; 
int shared=1; 
void *Thread_fun1(void *arg) {

   int x=shared; 
   x++; 
   cout<<"First_thread reads the value of shared variable as : 1"<<endl; 
   pthread_mutex_lock( &mutex1); 
   shared++;
   cout<<"Increment of shared variable by first_thread as : "<<x<<endl; 
   pthread_mutex_unlock( &mutex1 ); 
   return 0; 
} 


void *Thread_fun2(void *arg) {

   int y=shared; 
   y--; 
   cout<<endl<<"second_thread reads the value of shared variable as : " <<shared<<endl; 
   pthread_mutex_lock( &mutex1); 
   shared--; 
   cout<<"Decrement of shared variable by second_thread as : "<<y<<endl; 
   pthread_mutex_unlock( &mutex1 ); 
   return 0; 
}


 int main() {

   pthread_t first_thread; 
   pthread_t second_thread; 
   pthread_create(&first_thread, NULL, Thread_fun1, NULL); 
   pthread_create(&second_thread, NULL, Thread_fun2, NULL); 
   pthread_join(first_thread, NULL); 
   pthread_join(second_thread,NULL); 
   cout<<"Final value of shared is : "<<shared<<endl; 
   return 0; 
} 