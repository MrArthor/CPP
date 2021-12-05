#include<iostream>

using namespace std;
int main()
{
    int a[10],b[10],x[10];
    int WaitTime[10],TurnAroundTime[10],CompletionTime[10];
    int i,smallest,c=0,time,n;
    double Average=0,tt=0,End;

    cout<<"\nEnter the number of processes: ";  
    cin>>n;
    for(i=0; i<n; i++)
    {
        cout<<"\nEnter the arrival time of "<<i+1<<" process: ";  
        cin>>a[i];
    }
    for(i=0; i<n; i++)
    {
        cout<<"\nEnter the burst time of "<<i+1<<" process: ";  
        cin>>b[i];
    }
    for(i=0; i<n; i++)
        x[i]=b[i];

    b[9]=9999;
    for(time=0; c!=n; time++)
    {
        smallest=9;
        for(i=0; i<n; i++)
        {
            if(a[i]<=time && b[i]<b[smallest] && b[i]>0 )
                smallest=i;
        }
        b[smallest]--;

        if(b[smallest]==0)
        {
            c++;
            End=time+1;
            CompletionTime[smallest] = End;
            WaitTime[smallest] = End - a[smallest] - x[smallest];
            TurnAroundTime[smallest] = End - a[smallest];
        }
    }
    cout<<"Process"<<"\t"<< " Burst Time"<<"\t"<<"Arrival Time" <<"\t"<<"Wait Time" <<"\t"<<"TurnAround Time"<< "\t"<<" Completion Time"<<endl;
    for(i=0; i<n; i++)
    {
        cout<<"p"<<i+1<<"\t\t"<<x[i]<<"\t\t"<<a[i]<<"\t\t"<<WaitTime[i]<<"\t\t"<<TurnAroundTime[i]<<"\t\t"<<CompletionTime[i]<<endl;
        Average = Average + WaitTime[i];
        tt = tt + TurnAroundTime[i];
    }
    cout<<"\n\nAverage WaitTime time ="<<Average/n;
    cout<<"\nAverage TurnAroundTime time ="<<tt/n<<endl;
}
