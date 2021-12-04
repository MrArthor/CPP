#include <iostream>
using namespace std;
int main()
{
    int np,i,j;
    double BurstTime[20], WaitTime[20], TurnTime[20], ResponseTime[20], throughput, avwt = 0, avtat = 0, avrt = 0;
    cout << "Enter total number of processes(maximum 20): ";
    cin >> np;
    cout << "\nEnter Burst Time for Process\n";
    for (i = 0; i < np; i++)
    {
        cout << "P[" << i + 1 << "]: ";
        cin >> BurstTime[i];
    }
    WaitTime[0] = 0;
    ResponseTime[0] = 0;
    for (i = 1; i < np; i++)
    {
        WaitTime[i] = 0;
        ResponseTime[i] = 0;
        for (j = 0; j < i; j++)
        {
            WaitTime[i] += BurstTime[j];
            ResponseTime[i] += BurstTime[j];
        }
    }
    cout<<"\nProcess\t\t Burst Time\t\tWaiting Time\t\tTurnaround Time\t\tResponse Time";
    for (i = 0; i < np; i++)
    {
        TurnTime[i] = BurstTime[i] + WaitTime[i];
        avwt += WaitTime[i];
        avrt += ResponseTime[i];
        avtat += TurnTime[i];
        cout<<"\nP["<<i+1<<"]"<<"\t\t\t"<<BurstTime[i]<<"\t\t\t"<<WaitTime[i]<<"\t\t\t"<< TurnTime[i]<<"\t\t\t"<<ResponseTime[i];
    }
    throughput = np / TurnTime[i - 1];
    avwt /= i;
    avtat /= i;
    avrt /= i;
    cout << "\n\nAverage Waiting Time: " << avwt;
    cout << "\n\nAverage Turnaround Time: " << avtat;
    cout << "\n\nAverage Response Time: " << avrt;
    cout << "\n\nThroughput: " << throughput << " process/unit time";
    return 0;
}