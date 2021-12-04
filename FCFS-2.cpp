#include <iostream>
using namespace std;
int main()
{
    int n, i;
    double ArrivalTime[20], BonusTIme[20], WaitTime[20], TurnTIme[20], ResponseTime[20];
    double st[20], ct[20];
    double throughput, avwt = 0, avtat = 0, avrt = 0;
    cout << "Enter total number of processes(maximum 20): ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "\nEnter Arrival Time: "
             << "P[" << i + 1 << "]: ";
        cin >> ArrivalTime[i];
        cout << "\nEnter Burst Time:  "
             << "P[" << i + 1 << "]: ";
        cin >> BonusTIme[i];
        cout << endl;
    }

    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            st[i] = ArrivalTime[i];
        }
        else
        {
            st[i] = st[i - 1] + BonusTIme[i - 1];
        }
        ct[i] = st[i] + BonusTIme[i];
        TurnTIme[i] = ct[i] - ArrivalTime[i];
        WaitTime[i] = TurnTIme[i] - BonusTIme[i];
        ResponseTime[i] = st[i] - ArrivalTime[i];
    }
    throughput = n / (ct[n - 1] - ArrivalTime[0]);
    cout << "\nProcess\t\t Burst Time\t\tWaiting Time\t\tTurnaround Time\t\tResponse Time";
    for (i = 0; i < n; i++)
    {
        avwt += WaitTime[i];
        avrt += ResponseTime[i];
        avtat += TurnTIme[i];
        cout << "\nP[" << i + 1 << "]\t\t\t" << BonusTIme[i] << "\t\t\t" << WaitTime[i] << "\t\t\t" << TurnTIme[i] << "\t\t\t" << ResponseTime[i];
    }
    avwt /= i;
    avtat /= i;
    avrt /= i;
    cout << "\n\nAverage Waiting Time: " << avwt;
    cout << "\n\nAverage Turnaround Time: " << avtat;
    cout << "\n\nAverage Response Time: " << avrt;
    cout << "\n\nThroughput: " << throughput << " process/unit time";
    return 0;
}