//Author : Kundan Kumar 
//Roll No: 207929
// Program to Implement Round Robin Scheduling. 
#include<bits/stdc++.h>
using namespace std;
struct process
{
	int Process_Id;
	int Arrival_time;
	int Burst_time;
	int mb_t;
	int completion_time;
	int Turn_Around_time;
	int Waiting_time;
	int Response_time;
	int f_t;
};

int main()
{
	int N,i,time_Quantum,ct=0,flag=0,min,temp;
	cout<<endl<<"Enter the No of processes for scheduling: ";
	cin>>N;
	cout<<endl;
    process p[N];
    for(i=0;i<N;i++)
	{
		cout<<"Enter ID for process: "; 
		cin>>p[i].Process_Id;
		cout<<"Enter Arrival time: ";
		cin>>p[i].Arrival_time;
        if(i==0)
		{
		min=p[i].Arrival_time;
		}
		if(min>p[i].Arrival_time)
		{
			min=p[i].Arrival_time;
		}
		cout<<"Enter Burst time: ";
		cin>>p[i].Burst_time;
        cout<<endl; 
		p[i].mb_t=p[i].Burst_time;
		p[i].f_t=0;
	}
	ct=min;
	cout<<"Enter the Time Quantum for scheduler: ";
	cin>>time_Quantum;
	while(true)
	{
		if(flag==N)
		{
			break;
		}
		flag=0;
		for(i=0;i<N;i++)
		{
			if(p[i].Arrival_time<=ct && p[i].mb_t>0)
			{
				if(p[i].mb_t==p[i].Burst_time)
				{
					p[i].Response_time=ct;
				}
				if((p[i].mb_t-time_Quantum)>=0)
				{
					p[i].mb_t=p[i].mb_t-time_Quantum;
					ct=ct+time_Quantum;
				}
				else
				{
					ct=ct+p[i].mb_t;
					p[i].mb_t=0;
				}
				if(p[i].mb_t==0)
				{
					p[i].completion_time=ct;
				}
			}	
		}
		for(i=0;i<N;i++)
		{
			if(p[i].mb_t==0)
			{
				flag++;
			}
		}
	}

	for(i=0;i<N;i++)
	{
		p[i].completion_time;
		p[i].Turn_Around_time=p[i].completion_time-p[i].Arrival_time;
		p[i].Waiting_time=p[i].Turn_Around_time-p[i].Burst_time;
	}

    //Finding Average Waiting Time and Average Turn Around Time. 
    int waiting_time_counter = 0; 
    int Turn_Around_time_counter = 0; 
    int response_time_counter = 0; 
    for(int i=0; i<N; i++){
        waiting_time_counter+=p[i].Waiting_time; 
        Turn_Around_time_counter+=p[i].Turn_Around_time;
        response_time_counter+=p[i].Response_time;  
    }

    cout<<endl<<endl<<"Final Output "<<endl; 
	cout<<"Process ID"<<"	"<<"Arrival time"<<"     "<<"Burst time"<<" 	 "<<"Completion time"<<"   "<<"turn_around_time"<<"	 "<<"waiting_time"<<"  	 "<<"response_time"<<endl;
	for(i=0;i<N;i++)
	{
		cout<<p[i].Process_Id<<"		 "<<p[i].Arrival_time<<"		 "<<p[i].Burst_time<<"		 "<<p[i].completion_time<<"			 "<<p[i].Turn_Around_time<<"		 "<<p[i].Waiting_time<<"	   	 "<<p[i].Response_time<<endl;
	}

    cout<<endl<<"Average Waiting time: "<<(float)waiting_time_counter/(float)N; 
    cout<<endl<<"Average Turn Around Time: "<<(float)Turn_Around_time_counter/(float)N; 
    cout<<endl<<"Average Response Time: "<<(float)response_time_counter/(float)N; 

	return 0;
	cout<<"SCHEDULING DONE";
}