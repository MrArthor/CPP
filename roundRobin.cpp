#include<iostream>
#include<cstdlib>
#include<queue>
#include<cstdio>
using namespace std;

typedef struct process
{
	int id,at,bt,st,ft,pr;
	float wt,tat;
}process;

process p[10],p1[10],temp;
queue<int> q1;

int accept()
{
	int i,n;
 
	cout<<"Enter the Total Number of Process: ";
	cin>>n;
  
	if(n==0)
	{
		printf("Invalid");
		exit(1);
	}
  
	cout<<endl;
  
	for(i=1;i<=n;i++)
	{
		cout<<"Enter an Arrival Time of the Process P"<<i<<": ";
		cin>>p[i].at;
		p[i].id=i;
	}

	cout<<endl;
  
	for(i=1;i<=n;i++)
	{
		cout<<"Enter a Burst Time of the Process P"<<i<<": ";
		cin>>p[i].bt;
	} 
 
	for(i=1;i<=n;i++)
	{
		p1[i]=p[i];
	}
	return n;
}

void ganttrr(int n)
{ 
	int i,ts,m,nextval; 
 
	nextval=p1[1].at;
	i=1;
 
	cout<<"\nEnter the Time Slice or Quantum: ";
	cin>>ts;
 
	for(i=1;i<=n && p1[i].at<=nextval;i++)
	{
		q1.push(p1[i].id);
	}
 
	while(!q1.empty()) 
	{ 
		m=q1.front();
		q1.pop();
  
		if(p1[m].bt>=ts)
		{
			nextval=nextval+ts;
		} 
		else
		{
			nextval=nextval+p1[m].bt;
		}   
		if(p1[m].bt>=ts)
		{
			p1[m].bt=p1[m].bt-ts;
		} 
		else
		{
			p1[m].bt=0;
		}   
  
		while(i<=n&&p1[i].at<=nextval)
		{
			q1.push(p1[i].id);
			i++;
		}
  
		if(p1[m].bt>0)
		{
			q1.push(m);
		}
		if(p1[m].bt<=0)
		{
			p[m].ft=nextval;
		}   
	}
}

void turnwait(int n)
{
	int i; 
 
	for(i=1;i<=n;i++)
	{
		p[i].tat=p[i].ft-p[i].at;
		p[i].wt=p[i].tat-p[i].bt;
		p[0].tat=p[0].tat+p[i].tat;
		p[0].wt=p[0].wt+p[i].wt;
	}   
 
	p[0].tat=p[0].tat/n;
	p[0].wt=p[0].wt/n;
}

void display(int n)
{
	int i;
  
	/*
	Here 
	at = Arrival time,
	bt = Burst time,
	time_quantum= Quantum time
	tat = Turn around time,
	wt = Waiting time
	*/ 
 
	cout<<"\nProcess\t Arrival Time\t  Burst Time\t Turn Around Time\tWaiting Time";
 
	for(i=1;i<=n;i++)
	{
		cout<<"\n"<<p[i].id<<"\t\t "<<p[i].at<<"\t\t "<<p[i].bt<<"\t\t "<<p[i].tat<<"\t\t\t "<<p[i].wt;
	}
  
   cout<<"\n\nAverage Turn Around Time: "<<p[0].tat;
   cout<<"\nAverage Waiting Time: "<<p[0].wt;
}

int main()
{
  int n;

  p[0].tat=0;
  p[0].wt=0;
 
  n=accept();
  ganttrr(n);
  turnwait(n);
  
 display(n);
  
 return 0;
}

