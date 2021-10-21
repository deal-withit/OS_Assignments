// Author : Kundan Kumar 
// Roll No: 207929
// Program to Implement Round Robin Scheduling Algorithm Where Time Quantum is the 
// difference of Maximum Burst Time and Minimum Burst Time. 
#include<bits/stdc++.h>                                     
using namespace std;                                                                                                                                                          
struct process
{
    //These all are the dynamic arrays which will be further used to store Arrival time, Burst time , Turn Around Time etc.    
    vector<int>Process_id;                                                                                           
    vector<int> Arr_time;                                                      
    vector<int> Br_time;                                                      
    vector<int> st;                                                      
    vector<int> comp_time;                                             
    vector<int> turnaroundtime;                                
    vector<int> wati_t;                                                      
    vector<int> resp_t;                                   

};
                                                                                                               
class compare1{

  public:
  bool  operator()(vector<int> &V1, vector<int>&V2){
      if(V1[1]==V2[1]){
          return V1[0]<V2[0];
      }
      return V1[1]<V2[1];
  }

};


int main()
{                                                                                                           
    int n,Time_Quantum;
    cout<<"Enter the number of processes: ";
    cin>>n;
    struct process p[100];//struct being  called to store the data into vectors 
    float avrg_tat;
    float avrg_wt;
    float avrg_rt;


    int total_tat = 0;
    int total_wt = 0;
    int total_rt = 0;
    int total_idle_time = 0;
    int Rem_Burst[n];
    int is_completed[n];
    memset(is_completed,0,sizeof(is_completed));
    cout << setprecision(2) << fixed;

    int max_burst_time=INT_MIN;
    int min_burst_time=INT_MAX;
    vector<vector<int> >v;
    for(int i = 0; i < n; i++) {
        
         vector<int>temp(9,0);
        cout<<"Enter process id: ";
        int x;
        cin>>x;
        temp [0]=x;
        cout<<"Enter arrrival time: ";
        int y;
        cin>>y;
        temp [1]=y;
        cout<<"Enter Burst time: ";
        int z;
        cin>>z;
        temp [2]=z;

        if(min_burst_time==INT_MAX){
            min_burst_time=z;
        }
        else if(min_burst_time>z)
        {
            min_burst_time=z;
        }

        
        if(max_burst_time==INT_MIN){
            max_burst_time=z;
        }
        else if(max_burst_time<z)
        {
            max_burst_time=z;
        }
        
        v.push_back(temp);
        Rem_Burst[i]=v[i][2];
        cout<<endl;
    }

    
   Time_Quantum=max_burst_time-min_burst_time;
   sort(v.begin(),v.end(),compare1());
    queue<int> q;
    int current_time = 0;
    q.push(0);
    int completed = 0;
    int mark[100];
    mark[0] = 1;
    
    while(completed != n) {
         int flag = q.front();
        q.pop();
        if(Rem_Burst[flag]==v[flag][2])
        {
        	v[flag][3]=max(current_time,v[flag][1]);
        	total_idle_time+=v[flag][3]-current_time;
        	current_time=v[flag][3];
		}
		if(Rem_Burst[flag]-Time_Quantum >0)
		{
			Rem_Burst[flag]-=Time_Quantum;
			current_time+=Time_Quantum;
		}
		else
		{
			current_time+=Rem_Burst[flag];
			Rem_Burst[flag]=0;
			completed++;
			v[flag][4]=current_time;
			v[flag][5]=v[flag][4]-v[flag][1];
			v[flag][6]=v[flag][5]-v[flag][2];
			v[flag][7]=v[flag][3]-v[flag][1];
			total_tat +=v[flag][5];
			total_wt += v[flag][6];
			total_rt +=v[flag][7];
		}
		for(int i=1;i<n;i++)
		{
			if(Rem_Burst[i]>0 && v[flag][1] <= current_time && mark[i]==0)
			{
				q.push(i);
				mark[i]=1;
			}
		}
		if(Rem_Burst[flag]>0)
 		{
			q.push(flag);
		}
		if(q.empty())
		{
			for(int i=1;i<n;i++)
			{
				if(Rem_Burst[i]>0)
				{
					q.push(i);
					mark[i]=1;
					break;
				}
			}
		}
    }
    
 
    avrg_tat = (float) total_tat / (float)n;
    avrg_wt = (float) total_wt /(float) n;
    avrg_rt = (float) total_rt / (float)n;

    cout<<endl;   
    cout<<"Average Turnaround Time = "<<avrg_tat<<endl;
    cout<<"Average Waiting Time = "<<avrg_wt<<endl;
    cout<<"Average Response Time = "<<avrg_rt<<endl;
    return 0;
}