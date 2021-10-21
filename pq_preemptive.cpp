//Author : Kundan Kumar 
//Roll No : 207929
//Program to Implement Priority Queue (Preemptive). 
#include <bits/stdc++.h>
using namespace std;

#define totalprocess 5
class Test
{
	public:
    int Arrival_time,Burst_time,pr,pno;
};

Test process_Array[50];

bool comp(Test j1,Test j2)
{
if(j1.Arrival_time == j2.Arrival_time)
{
return j1.pr<j2.pr;
}
else
{
	return j1.Arrival_time<j2.Arrival_time;
}
}


void waitingtime(int waiting_time[])
{

int ex[50];


ex[0] = process_Array[0].Arrival_time;
waiting_time[0]=0;


for(int i=1;i<totalprocess;i++)
{
ex[i]=process_Array[i-1].Burst_time+ex[i-1];

waiting_time[i]=ex[i]-process_Array[i].Arrival_time;
	
	if(waiting_time[i]<0)
	{
	waiting_time[i]=0;
	}
}

}

void TurnAroundTime(int tat[],int waiting_time[])
{


for(int i=0;i<totalprocess;i++)
{
	tat[i]=process_Array[i].Burst_time+waiting_time[i];
}
	
}

void findgc()
{

int waiting_time[50],tat[50];

double wavg=0,tavg=0;


waitingtime(waiting_time);

TurnAroundTime(tat,waiting_time);
	
int stime[50],ctime[50];

stime[0] = process_Array[0].Arrival_time;
ctime[0]=stime[0]+tat[0];


for(int i=1;i<totalprocess;i++)
	{
		stime[i]=ctime[i-1];
		ctime[i]=stime[i]+tat[i]-waiting_time[i];
	}
	
cout<<"Process_no\tStart_time\tComplete_time\tTurn_Around_Time\tWaiting_Time"<<endl;
	
	
	
for(int i=0;i<totalprocess;i++)
	{
		wavg += waiting_time[i];
		tavg += tat[i];
		
		cout<<process_Array[i].pno<<"\t\t"<<stime[i]<<"\t\t"<<ctime[i]<<"\t\t"<<tat[i]<<"\t\t\t"<<waiting_time[i]<<endl;
	}
	cout<<"Average waiting time is : ";
	cout<<wavg/(float)totalprocess<<endl;
	cout<<"average turnaround time : ";
	cout<<tavg/(float)totalprocess<<endl;

}

int main()
{
	int n;
	cout<<"Enter the number of Test \n";
	cin>>n;
    int arrivaltime[n];
    int bursttime[n];
    int priority[n];
	    cout<<"Enter Priority , Arrival Time and Burst time of all the "<<n<<" Process \n";
	    for(int i=0;i<n;i++)
	    {   
	    cout<<"Process "<<i+1<<endl;
	    	cout<<"Enter Priority :";
	    	cin>>priority[i];
	    	cout<<"Enter Arrival Time  :";
	    	cin>>arrivaltime[i];
	    	cout<<"Enter Burst Time  :";
	    	cin>>bursttime[i];
		}
	
for(int i=0;i<totalprocess;i++)
{
	process_Array[i].Arrival_time=arrivaltime[i];
	process_Array[i].Burst_time=bursttime[i];
	process_Array[i].pr=priority[i];
	process_Array[i].pno=i+1;
	}
	sort(process_Array,process_Array+totalprocess,comp);
	findgc();

	return 0;
}