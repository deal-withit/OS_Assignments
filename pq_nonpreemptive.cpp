//Author : Kundan Kumar 
//Roll No: 207929
//Program to Implement Priority Queue (Non Preemptive)
#include<iostream>
using namespace std;
int main()
{
    //Arrays for Arrival time, Burst time
    int Arrival_array[10],Burst_Array[10],Temp_array[10],Process_array[10]={0};
    //Arrays to store Waiting time, turn around time and completion_Time time 
    int Waiting_time[10],turnaround_Time[10],completion_Time[10];
    int i,j,Minimum,count=0,time,no_of_Process;
    double avg=0,turnAround_Time=0,end;
    cout<<"\nEnter the number of Processes: ";
    cin>>no_of_Process;
    cout<<"Enter Priority Arrival Time and Burst Time \n";
    for(i=0;i<no_of_Process;i++)
    {
    	 cout<<"Process P"<<i+1<<endl;
    	 cout<<"Enter priority : ";
         cin>>Process_array[i];
         cout<<"Enter Arrival time : ";
          cin>>Arrival_array[i];
         cout<<"Enter Burst time : ";
         cin>>Burst_Array[i];
    }
    for(i=0;i<no_of_Process;i++)
        Temp_array[i]=Burst_Array[i];

    Process_array[9]=-1;
    for(time=0;count!=no_of_Process;time++)
    {
        Minimum=9;
        for(i=0;i<no_of_Process;i++)
        {
            if(Arrival_array[i]<=time && Process_array[i]>Process_array[Minimum] && Burst_Array[i]>0 )
                Minimum=i;
        }
        time+=Burst_Array[Minimum]-1;
        Burst_Array[Minimum]=-1;
        count++;
        end=time+1;
        completion_Time[Minimum] = end;
        Waiting_time[Minimum] = end - Arrival_array[Minimum] - Temp_array[Minimum];
        turnaround_Time[Minimum] = end - Arrival_array[Minimum];
    }
    cout<<"Process"<<"\t"<< "burst-time"<<"\t"<<"arrival-time" <<"\t"<<"Waiting_time-time" <<"\t"<<"turnaround_Time-time"<< "\t"<<"completion_Time-time"<<"\t"<<"Priority"<<endl;
    for(i=0;i<no_of_Process;i++)
    {
        cout<<"p"<<i+1<<"\t\t"<<Temp_array[i]<<"\t\t"<<Arrival_array[i]<<"\t\t"<<Waiting_time[i]<<"\t\t"<<turnaround_Time[i]<<"\t\t"<<completion_Time[i]<<"\t\t"<<Process_array[i]<<endl;
        avg+=Waiting_time[i];
        turnAround_Time += turnaround_Time[i];
    }
    cout<<endl<<endl; 
    cout<<"Average Waiting_time time ="<<avg/no_of_Process<<endl;
    cout<<"  Average Turnaround time ="<<turnAround_Time/no_of_Process<<endl;
}