#include <bits/stdc++.h>
#define loop(i,n) for(int i=0;i<n;i++)
#define fors(i,n) for(int i=1;i<=n;i++)
using namespace std;

struct Process {
    int pid;
    int bt;
    int art;
};

void findWaitingTime(Process proc[], int n, int wt[])
{
    int rt[n];

    // Copy the burst time into rt[]
    for (int i = 0; i < n; i++)
        rt[i] = proc[i].bt;

    int complete = 0, t = 0, minm = INT_MAX;
    int shortest = 0, finish_time;
    bool check = false;

    while (complete != n) {

        for (int j = 0; j < n; j++) {
            if ((proc[j].art <= t) &&
            (rt[j] < minm) && rt[j] > 0) {
                minm = rt[j];
                shortest = j;
                check = true;
            }
        }

        if (check == false) {    //this condition work when cpu is idle
            t++;
            continue;
        }


        rt[shortest]--;


        minm = rt[shortest];
        if (minm == 0)
            minm = INT_MAX;

        if (rt[shortest] == 0) {
            complete++;
            check = false;

            finish_time = t + 1;

            wt[shortest] = finish_time -
                        proc[shortest].bt -
                        proc[shortest].art;

            if (wt[shortest] < 0)
                wt[shortest] = 0;
        }

        t++;
    }
}


void findTurnAroundTime(Process proc[], int n,
                        int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
        tat[i] = proc[i].bt + wt[i];
}

void findavgTime(Process proc[], int n)
{
    int wt[n], tat[n], total_wt = 0,
                    total_tat = 0;

    findWaitingTime(proc, n, wt);


    findTurnAroundTime(proc, n, wt, tat);

    cout << "Processes "
        << " Burst time "
        << " Waiting time "
        << " Turn around time\n";


    for (int i = 0; i < n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << proc[i].pid << "\t\t"
            << proc[i].bt << "\t\t " << wt[i]
            << "\t\t " << tat[i] << endl;
    }

    cout << "\nAverage waiting time = "
        << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
        << (float)total_tat / (float)n;
}

int main()
{   int n,a,b,c;
    cout<<"enter the no. of processes:";
    cin>>n;
    Process proc[n];
    loop(i,n)
    {
    cout<<"enter the PID, BT, AT respectively:";
    cin>>a>>b>>c;
    proc[i].pid=a;
    proc[i].bt=b;
    proc[i].art=c;
    }

    findavgTime(proc, n);
    return 0;
}
