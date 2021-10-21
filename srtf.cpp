//Author: Kundan Kumar
//Roll No : 207929
//Program to Implement Shortest Remaining Time First Algorithm 

#include<iostream>
using namespace std;
int main()
{
    //Arrays to store the Arrival Time and Burst time for different processes. 
    int Arrival_Array[10],Burst_Array[10],temp_Array[10];
    //Arrays to store the Waiting Time, Turn Around Time and Completion Time. 
    int waiting_time[10],turnAround_time[10],completion_Time[10];
    int i,j,minimum,counter=0,time,n;
    double avg=0,tt=0,end;

    cout<<"Enter the number of Processes: ";  
    cin>>n;
    cout<<endl; 
    for(i=0; i<n; i++)
    {
        cout<<"Enter Arrival time for P"<<i<<"  ";  
        cin>>Arrival_Array[i];
        cout<<endl; 
    }
    for(i=0; i<n; i++)
    {
        cout<<"Enter Burst time for P"<<i<<"  "; 
        cin>>Burst_Array[i];
        cout<<endl; 
    }
    for(i=0; i<n; i++)
        temp_Array[i]=Burst_Array[i];

    Burst_Array[9]=9999;
    for(time=0; counter!=n; time++)
    {
        minimum=9;
        for(i=0; i<n; i++)
        {
            if(Arrival_Array[i]<=time && Burst_Array[i]<Burst_Array[minimum] && Burst_Array[i]>0 )
                minimum=i;
        }
        Burst_Array[minimum]--;

        if(Burst_Array[minimum]==0)
        {
            counter++;
            end=time+1;
            completion_Time[minimum] = end;
            waiting_time[minimum] = end - Arrival_Array[minimum] - temp_Array[minimum];
            turnAround_time[minimum] = end - Arrival_Array[minimum];
        }
    }
    cout<<"Process"<<"\t"<< "Burst Time"<<"\t"<<"Arrival Time" <<"\t"<<"Waiting Time" <<"\t"<<"Turn Around Time"<< "\t"<<"completion_Time Time"<<endl;
    for(i=0; i<n; i++)
    {
        cout<<"P"<<i<<"\t\t"<<temp_Array[i]<<"\t\t"<<Arrival_Array[i]<<"\t\t"<<waiting_time[i]<<"\t\t"<<turnAround_time[i]<<"\t\t"<<completion_Time
[i]<<endl;
        avg += waiting_time[i];
        tt += turnAround_time[i];
    }
    cout<<endl<<endl; 
    cout<<"Average Waiting Time ="<<avg/n<<endl;
    cout<<"Average Turn Around Time ="<<tt/n<<endl;
}