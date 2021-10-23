//Author : Kundan Kumar 
//Roll No: 207929
//Assignment 05, QNo. 1 Solution 
#include<bits/stdc++.h> 
#include<pthread.h> 
#include<unistd.h> 
using namespace std; 
int temp=1; 
void *thread_1(void *arg) 
{ 
     int x; 
     x=temp; 
     cout<<"First Thread value of shared Variable: "<<x<<endl;  
     x++; 
     cout<<"After Increment of shared variable by first thread: "<<x<<endl; 
     sleep(1); 
     temp=x; 
    cout<<"Value of shared variable updated by first_thread is: "<<temp<<endl;
 return 0;  
} 
void *thread_2(void *arg)
{ 
   int y; 
   y=temp; 
   cout<<endl<<"second_thread reads the value of temp variable as :"<<y<<endl; 
   y--; 
   cout<<"Decrement of temp variable by second_thread as : "<<y<<endl;
   sleep(1); 
   temp=y; 
   cout<<endl<<"Value of temp variable updated by second_thread is: "<<temp<<endl; 
   return 0; 
 } 
 
 int main() 
 { 
    pthread_t first_thread; 
    pthread_t second_thread; 
    pthread_create(&first_thread, NULL, thread_1, NULL); 
    pthread_create(&second_thread, NULL, thread_2, NULL); 
    pthread_join(first_thread, NULL); 
    pthread_join(second_thread,NULL); 
    cout<<"Final value of temp is : "<<temp<<endl; 
    return 0; 
 } 