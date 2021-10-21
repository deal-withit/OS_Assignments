#include<iostream>
using namespace std;
int main()
{
    int Arrival[10],burst[10],x[10];
    int waiting_time[10],turnAround_time[10],completion_Time[10];
    int i,j,Min,count=0,time,n;
    double avg=0,tt=0,end;

    cout<<"Enter the number of Processes: ";  
    cin>>n;
    cout<<endl; 
    for(i=0; i<n; i++)
    {
        cout<<"Enter Arrival time for P"<<i<<"  ";  
        cin>>Arrival[i];
        cout<<endl; 
    }
    for(i=0; i<n; i++)
    {
        cout<<"Enter Burst time for P"<<i<<"  "; 
        cin>>burst[i];
        cout<<endl; 
    }
    for(i=0; i<n; i++)
        x[i]=burst[i];

    burst[9]=9999;
    for(time=0; count!=n; time++)
    {
        Min=9;
        for(i=0; i<n; i++)
        {
            if(Arrival[i]<=time && burst[i]<burst[Min] && burst[i]>0 )
                Min=i;
        }
        burst[Min]--;

        if(burst[Min]==0)
        {
            count++;
            end=time+1;
            completion_Time[Min] = end;
            waiting_time[Min] = end - Arrival[Min] - x[Min];
            turnAround_time[Min] = end - Arrival[Min];
        }
    }
    cout<<"Process"<<"\t"<< "Burst Time"<<"\t"<<"Arrival Time" <<"\t"<<"Waiting Time" <<"\t"<<"Turn Around Time"<< "\t"<<"completion_Time Time"<<endl;
    for(i=0; i<n; i++)
    {
        cout<<"P"<<i<<"\t\t"<<x[i]<<"\t\t"<<Arrival[i]<<"\t\t"<<waiting_time[i]<<"\t\t"<<turnAround_time[i]<<"\t\t"<<completion_Time
[i]<<endl;
        avg += waiting_time[i];
        tt += turnAround_time[i];
    }
    cout<<endl; 
    cout<<"Average Waiting Time ="<<avg/n<<endl;
    cout<<"Average Turn Around Time ="<<tt/n<<endl;
}