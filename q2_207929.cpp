#include<bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <climits>

using namespace std;

class Process {
public:
    int p_id{};
    int s_time{};
    int end_time{};
    int arr_time{};
    int bur_time{};
    int res_time{};
    int tat_time{};
    int wt_time{};
    int rem_bur_time{};
    char type;

    bool is_completed;

    static int current_time;
    Process() {
        is_completed = false;
    }
};

int Process::current_time = 0;


int main() {
    int number_of_processes;

    cout << endl;
    cout << "Priority Scheduling Algorithm (Preemptive)" << endl;
    cout << endl;

    cout << "Number of Processes: ";
    cin >> number_of_processes;
    if (number_of_processes <= 0) {
        cout << string(50, '-') << endl;
        cout << "Please enter a valid number of processes!" << endl;
        cout << string(50, '-') << endl;
        return -1;
    }

    Process process[number_of_processes];

    int total_response_time = 0;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    for (int i = 0; i < number_of_processes; i++) {
        cout << endl;
        cout << "Process" << (i + 1) << endl;
        cout  << endl;

        cout << " Enter Arrival Time: ";
        cin >> process[i].arr_time;

        cout << "Enter Burst Time: ";
        cin >> process[i].bur_time;

        cout << "Enter Process Type";
        cin >> process[i].type;

        if (process[i].type != 'x' && process[i].type != 'y' && process[i].type != 'X' && process[i].type != 'Y') {
            
            cout <<endl<<"Unvalid Type!" << endl;
            
            return -1;
        }

        process[i].p_id = i + 1;
        process[i].rem_bur_time = process[i].bur_time;
    }

    cout << endl;

    int completed = 0;

    cout << endl;
    cout << "Gantt Chart" << endl;
    cout << endl;

    while (completed != number_of_processes) {
        int index = INT_MIN;

        for (int i = 0; i < number_of_processes; i++) {
            if (process[i].arr_time <= Process::current_time &&
                !process[i].is_completed) {
                index = i;

                if (process[i].type == 'x' || process[i].type == 'X') {
                    if (process[i].arr_time <
                        process[index].arr_time) {
                        index = i;
                    }
                }
            }
        }

        if (index != INT_MIN) {
            if (process[index].rem_bur_time == process[index].bur_time) {
                
                process[index].s_time = Process::current_time;
            }

            if (process[index].type == 'x' || process[index].type == 'X') {
                process[index].rem_bur_time -= process[index].bur_time;

                for (int k = Process::current_time; k <= Process::current_time + process[index].bur_time; k++) {
                    cout << k << " - " << k + 1 << ": P";
                }

                Process::current_time += process[index].bur_time;
            } else {
                process[index].rem_bur_time -= 1;
                Process::current_time += 1;
            }

            if (process[index].rem_bur_time == 0) {
               
                process[index].end_time = Process::current_time;

                
                process[index].tat_time =
                        process[index].end_time - process[index].arr_time;

                
                process[index].wt_time = process[index].tat_time -
                                              process[index].bur_time;

            
                process[index].res_time =
                        process[index].s_time - process[index].arr_time;

                total_turnaround_time += process[index].tat_time;
                total_waiting_time += process[index].wt_time;
                total_response_time += process[index].res_time;

                process[index].is_completed = true;
                completed += 1;
            }
        } else {
            Process::current_time += 1;
        }
    }

    double average_turnaround_time =
            (double) total_turnaround_time / number_of_processes;
    double average_waiting_time =
            (double) total_waiting_time / number_of_processes;
    double average_response_time =
            (double) total_response_time / number_of_processes;

    cout << endl;
    cout.setf(ios::left);
    cout << setw(15) << "Process ID" << setw(15) << "Arrival Time" << setw(15)
         << "Burst Time" << setw(15)
         << "Start Time" << setw(15) << "End Time" << setw(15) << "Waiting Time"
         << setw(15) << "Response Time"
         << setw(15) << "Turnaround Time" << endl;
    cout.unsetf(ios::left);
    cout << endl;

    for (int i = 0; i < number_of_processes; i++) {
        cout << setw(6) << process[i].p_id << " (" << process[i].type << ")" << setw(15)
             << process[i].arr_time << setw(15)
             << process[i].bur_time << setw(15) << process[i].s_time
             << setw(15) << process[i].end_time
             << setw(15) << setw(15) << process[i].wt_time << setw(15)
             << process[i].res_time << setw(15)
             << process[i].tat_time << endl;
    }

    cout << endl;

    cout << endl;
    cout << "Total Turnaround Time: " << total_turnaround_time << " unit"
         << endl;
    cout << "Total Waiting Time: " << total_waiting_time << " unit" << endl;
    cout << "Total Response Time: " << total_response_time << " unit" << endl;
    cout << endl;

    cout << "Average Turnaround Time: " << average_turnaround_time << " unit"
         << endl;
    cout << "Average Waiting Time: " << average_waiting_time << " unit" << endl;
    cout << "Average Response Time: " << average_response_time << " unit"
         << endl;
    cout << endl;

    return 0;
}