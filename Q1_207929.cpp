#include <iostream>
#include <algorithm> 
#include <iomanip>
#include <queue> 
using namespace std;

struct rrscheduling {
    int process_no;
    int Arr_time;
    int Bur_time;
    int St_time;
    int Com_time;
    int Turn_time;
    int Wait_time;
    int Res_time;
};

bool at_sort(rrscheduling p1, rrscheduling p2) 
{ 
    return p1.Arr_time < p2.Arr_time;
}

bool at_pno(rrscheduling p1, rrscheduling p2) 
{  
    return p1.process_no < p2.process_no;
}
 main() {

    struct rrscheduling p[100];
    int n,quant=0,total_tat = 0,total_wt = 0,total_rt = 0, total_idle = 0,temp[100],process_no;
    float avg_tat, avg_wt,avg_rt,throughput;
    vector<int> time_quantum;
    float low_quart=0,upper_quart=0;
    cout<<"Enter the number of processes: ";
    cin>>n;
    for(int i = 0; i < n; i++) {
        cout<<"For Process  "<<i+1<<"\nEnter Arrival Time :\t";
        cin>>p[i].Arr_time;
        cout<<"Enter burst time :\t";
        cin>>p[i].Bur_time;
        temp[i] = p[i].Bur_time;
        p[i].process_no = i+1;
        cout<<endl;
    }
    for(int i=0;i<n;i++)
    {
    	time_quantum.push_back(temp[i]);
	}
    sort(time_quantum.begin(),time_quantum.end());
    if(n%2!=0)
    {
      low_quart=time_quantum[(n+1)/4];
	  upper_quart=time_quantum[3*(n+1)/4];
	}
	else
	{
		low_quart=(time_quantum[n/4]+time_quantum[n/4+1])/2;
		upper_quart=(time_quantum[3*n/4]+time_quantum[3*(n/4+1)])/2;
	}
	quant=upper_quart-low_quart;
	cout<<"Upper Quartile = "<<upper_quart<<"\nLower Quartile = "<<low_quart;
	
    sort(p,p+n,at_sort);

    queue<int> process_queue;
    int current_time = 0;
    process_queue.push(0);
    int completed = 0;
    int mark[100]={0};
    mark[0] = 1;

    while(completed != n) {
        process_no = process_queue.front();
        process_queue.pop();

        if(temp[process_no] == p[process_no].Bur_time) {
            p[process_no].St_time = max(current_time,p[process_no].Arr_time);
            total_idle += p[process_no].St_time - current_time;
            current_time = p[process_no].St_time;
        }

        if(temp[process_no]-quant > 0) {
            temp[process_no] -= quant;
            current_time += quant;
        }
        else {
            current_time += temp[process_no];
            temp[process_no] = 0;
            completed++;

            p[process_no].Com_time = current_time;
            p[process_no].Turn_time = p[process_no].Com_time - p[process_no].Arr_time;
            p[process_no].Wait_time = p[process_no].Turn_time - p[process_no].Bur_time;
            p[process_no].Res_time = p[process_no].St_time - p[process_no].Arr_time;

            total_tat += p[process_no].Turn_time;
            total_wt += p[process_no].Wait_time;
            total_rt += p[process_no].Res_time;
        }

        for(int i = 1; i < n; i++) {
            if(temp[i] > 0 && p[i].Arr_time <= current_time && mark[i] == 0) {
                process_queue.push(i);
                mark[i] = 1;
            }
        }
        if(temp[process_no] > 0) {
            process_queue.push(process_no);
        }

        if(process_queue.empty()) {
            for(int i = 1; i < n; i++) {
                if(temp[i] > 0) {
                    process_queue.push(i);
                    mark[i] = 1;
                    break;
                }
            }
        }
    }

    avg_tat =total_tat / n;
    avg_wt = total_wt / n;
    avg_rt = total_rt / n;
    sort(p,p+n,at_pno);
    cout<<endl;
    cout<<"   Process\t "<<"Arrival   "<<"  Burst\t"<<"Start\t"<<" Complete  "<<" TurnAround\t"<<" Waiting   "<<" Response\t"<<"\n"<<endl;

    for(int i = 0; i < n; i++) {
        cout<<"  "<<p[i].process_no<<"\t\t   "<<p[i].Arr_time<<"\t\t"<<p[i].Bur_time<<" \t  "<<p[i].St_time<<"   \t   "<<p[i].Com_time<<"\t      "<<p[i].Turn_time<<"\t  "<<p[i].Wait_time<<"  \t  "<<p[i].Res_time<<endl;
    }
    cout<<"\nAverage Turnaround Time =\t"<<avg_tat<<endl;
    cout<<"Average Waiting Time =\t"<<avg_wt<<endl;
    cout<<"Average Response Time =\t"<<avg_rt<<endl;

}