#include<iostream>

using namespace std;
int main()
{
    int ArrivalTime[10],BurstTime[10],x[10],Priority[10]={0};
    int Waiting[10],TurnAround[10],completion[10];
    int i,smallest,count=0,time,n;
    double Average=0,tt=0,end;
    cout<<"\nEnter the number of Processes: ";
    cin>>n;
    for(i=0;i<n;i++)
    {
      cout<<"\nEnter the arrival time: ";
      cin>>ArrivalTime[i];
    }
    for(i=0;i<n;i++)
    {
      cout<<"\nEnter the burst time: ";
      cin>>BurstTime[i];
    }
    for(i=0;i<n;i++)
    {
      cout<<"\nEnter the priority: ";
      cin>>Priority[i];
    }
    for(i=0;i<n;i++)
        x[i]=BurstTime[i];

    Priority[9]=-1;
    for(time=0;count!=n;time++)
    {
        smallest=9;
        for(i=0;i<n;i++)
        {
            if(ArrivalTime[i]<=time && Priority[i]>Priority[smallest] && BurstTime[i]>0 )
                smallest=i;
        }
        time+=BurstTime[smallest]-1;
        BurstTime[smallest]=-1;
        count++;
        end=time+1;
        completion[smallest] = end;
        Waiting[smallest] = end - ArrivalTime[smallest] - x[smallest];
        TurnAround[smallest] = end - ArrivalTime[smallest];
    }
    cout<<"Process"<<"\t "<< "Burst Time"<<"\t"<<"Arrival Time" <<"\t "<<"Waiting Time" <<"\t "<<"TurnAround Time"<< "\t "<<"Completion Time"<<"\t "<<"Priority"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<"p"<<i+1<<"\t\t"<<x[i]<<"\t\t"<<ArrivalTime[i]<<"\t\t"<<Waiting[i]<<"\t\t"<<TurnAround[i]<<"\t\t\t"<<completion[i]<<"\t\t"<<Priority[i]<<endl;
        Average = Average + Waiting[i];
        tt = tt + TurnAround[i];
    }
    cout<<"\n\nAverage Waiting time: "<<Average/n;
    cout<<"\nAverage TurnAround time: "<<tt/n<<endl;
}
