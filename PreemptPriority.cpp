#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

typedef struct proccess
{
	int ArrivalTime,BurstTime,ct,TurnAround,WaitTime,btt,Priority;
	string pro_id;
}schedule;

bool compare(schedule a,schedule b)
{
	return a.ArrivalTime<b.ArrivalTime;
}

bool compare2(schedule a,schedule b)
{
	return a.Priority>b.Priority;
}

int main()
{
	schedule pro[10];
	int n,i,j,pcom;

	cout<<"Enter the number of process: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter the process ID of "<<i+1<<" process: ";
		cin>>pro[i].pro_id;
	}
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter the arrival time of "<<i+1<<" process: ";
		cin>>pro[i].ArrivalTime;
	}
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter the burst time of "<<i+1<<" process: ";
		cin>>pro[i].BurstTime;
	}
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter the priority of "<<i+1<<" process: ";
		pro[i].btt=pro[i].BurstTime;
		cin>>pro[i].Priority;
	}

	sort(pro,pro+n,compare);   //predefined func to sort schedules acc to AT

	i=0;
	pcom=0;
	while(pcom<n)
	{
		for(j=0;j<n;j++)
		{
			if(pro[j].ArrivalTime>i)
			break;
		}
		sort(pro,pro+j,compare2);
		if(j>0)
		{
			for(j=0;j<n;j++)
			{
				if(pro[j].BurstTime!=0)
				break;
			}
			if(pro[j].ArrivalTime>i)
			i+=pro[j].ArrivalTime-i;
			pro[j].ct=i+1;
			pro[j].BurstTime--;
		}
		
		i++;
		pcom=0;
		for(j=0;j<n;j++)
		{
			if(pro[j].BurstTime==0)
			pcom++;
		}
	}
	float avgWaitTime=0, avgTurnAroundt=0;
	cout<<"\nP_Id\t Arrival Time\t Burst Time\t Completion Time\t Turnaround Time\t Waiting Time\t Priority\n";
	for(i=n-1;i>=0;i--)
	{
		pro[i].TurnAround=pro[i].ct-pro[i].ArrivalTime;
		pro[i].WaitTime=pro[i].TurnAround-pro[i].btt;
		avgWaitTime+=pro[i].WaitTime;
		avgTurnAroundt+=pro[i].TurnAround;
		cout<<pro[i].pro_id<<"\t\t"<<pro[i].ArrivalTime<<"\t\t"<<pro[i].btt<<"\t\t"<<pro[i].ct<<"\t\t\t"<<pro[i].TurnAround<<"\t\t"<<pro[i].WaitTime<<"\t\t"<<pro[i].Priority;
		cout<<endl;
	}
	cout<<"\nAverage waiting time: "<<avgWaitTime/n;
	cout<<"\nAverage turnaround time: "<<avgTurnAroundt/n;
	return 0;
}
