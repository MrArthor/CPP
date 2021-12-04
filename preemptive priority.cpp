//Implementation of Priority(Preeemptive) Using C++
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

typedef struct proccess
{
	int at,bt,ct,ta,wt,btt,pr;
	string pro_id;
	/*
	artime = Arrival time,
	bt = Burst time,
	ct = Completion time,
	ta = Turn around time,
	wt = Waiting time
	*/

}schedule;

bool compare(schedule a,schedule b)
{
	return a.at<b.at;
	/* This schedule will always return TRUE
	if above condition comes*/
}

bool compare2(schedule a,schedule b)
{
	return a.pr>b.pr;
	/* This schedule will always return TRUE
	if above condition comes*/
}

int main()
{
	schedule pro[10];
	int n,i,j,pcom;

	cout<<"Enter the number of process::";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter the Process id of process "<<i+1<<": ";
		cin>>pro[i].pro_id;
	}
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter arrival time of process "<<i+1<<": ";
		cin>>pro[i].at;
	}
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter burst time of process "<<i+1<<": ";
		cin>>pro[i].bt;
	}
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter priority of process "<<i+1<<": ";
		pro[i].btt=pro[i].bt;
		cin>>pro[i].pr;
	}

	sort(pro,pro+n,compare);
	/*sort is a predefined funcion  defined in 
	algorithm.h header file, it will sort the 
	schedulees according to their arrival time*/

	i=0;
	pcom=0;
	while(pcom<n)
	{
		for(j=0;j<n;j++)
		{
			if(pro[j].at>i)
			break;
		}
		sort(pro,pro+j,compare2);
		if(j>0)
		{
			for(j=0;j<n;j++)
			{
				if(pro[j].bt!=0)
				break;
			}
			if(pro[j].at>i)
			i+=pro[j].at-i;
			pro[j].ct=i+1;
			pro[j].bt--;
		}
		
		i++;
		pcom=0;
		for(j=0;j<n;j++)
		{
			if(pro[j].bt==0)
			pcom++;
		}
	}
	float avgwt=0, avgtat=0;
	cout<<"\nP_Id\t Arrival Time\t Burst Time\t Completion Time\t Turnaround Time\t Waiting Time\t Priority\n";
	for(i=n-1;i>=0;i--)
	{
		pro[i].ta=pro[i].ct-pro[i].at;
		pro[i].wt=pro[i].ta-pro[i].btt;
		avgwt+=pro[i].wt;
		avgtat+=pro[i].ta;
		//before executing make it in one statement
		cout<<pro[i].pro_id<<"\t\t"<<pro[i].at<<"\t\t"<<pro[i].btt<<"\t\t"<<pro[i].ct<<"\t\t\t"<<pro[i].ta<<"\t\t"<<pro[i].wt<<"\t\t"<<pro[i].pr;
		cout<<endl;
	}
	cout<<"\nAverage waiting time: "<<avgwt/n;
	cout<<"\nAverage turnaround time: "<<avgtat/n;
	return 0;
}
