#include <iostream>
#include <fstream>
#define MAX 1000
using namespace std;

class node{
	public:
		int jno, st, ft, wt;
};

class wis{
	public:
		int count;
		node* jobs[MAX];
		int P[MAX], M[MAX];
	
	wis(){
		count=0;	
	}
	
	node* createnode(int, int, int);
	void sort();
	void defineprev();
	void findoptval();
	void findoptsol(int);
	void display();

};

node* wis::createnode(int s, int f, int w){
	node *temp=new node;
	temp->st=s;
	temp->ft=f;
	temp->wt=w;
	jobs[count]=temp;
	count++;
	return temp;		
}


void wis::sort(){
	int size=count;
	for (int i=0; i<size; i++){
		for(int j=0; j<(size-i-1); j++){
			if(jobs[j]->ft>jobs[j+1]->ft){
				swap(jobs[j],jobs[j+1]);
			}
		}
	}
	int jobno=1;
	for(int i=0; i<count; i++){
		jobs[i]->jno=jobno++;	
	}
}

void wis::defineprev(){
	for(int i=0; i<count; i++){
		for(int j=0; j<count; j++){
			if(i>j){
				if(jobs[i]->st>=jobs[j]->ft){
					P[i]=jobs[j]->jno;	
				}	
			}
			else if(j>i && P[i]>count){
				P[i]=0;
			}	
		}	
	}
	cout<<"P(j): "<<endl;
	for(int i=0; i<count; i++){
		cout<<P[i]<<"	";	
	}	
	cout<<endl;
}

void wis::findoptval(){
	int a, b;
	M[0]=0;
	for (int j=1; j<=count; j++){
		b=M[j-1];
		a=jobs[j-1]->wt + M[P[j-1]];
		if(a>b){
			M[j]=a;
		}
		else{
			M[j]=b;
		}
		//cout<<   j<<"Weight = "<<jobs[j-1]->wt<<" a  = "<<a<<"	b = "<<b<<endl;
	}
	cout<<endl<<"Optimal Value: "<<M[count]<<endl<<endl;
	cout<<"Optimal Solution: ";
	findoptsol(count);
}

void wis::findoptsol(int j){
	if (j==0){
		cout<<""<<endl;	
	}
	else{
		if ((jobs[j-1]->wt + M[P[j-1]]) > M[j-1]){
			cout<<jobs[j-1]->jno<<"	";
			findoptsol(P[j-1]);	
		}
		else{
			findoptsol(j-1);	
		}	
	}
		
}



void wis::display(){
	cout<<"Job No.	Start Time	Finish Time	Weight"<<endl;
	for (int i=0; i<count; i++){
		cout<<"  "<<jobs[i]->jno<<"	  "<<jobs[i]->st<<"		  "<<jobs[i]->ft<<"		  "<<jobs[i]->wt<<endl;			
	}
	cout<<endl<<endl;
	cout<<"Number of jobs: "<<count<<endl<<endl;
}


int main(){
	
	wis obj;
	int start, finish, weight;
	cout<<"----------------SORTING WRT FINISH TIME---------------"<<endl<<endl;
		
	ifstream datainfo("wisdata.txt");
	while(datainfo >> start >> finish >> weight){
		obj.createnode(start, finish, weight);
	}
	obj.sort();
	obj.display();
	obj.defineprev();
	obj.findoptval();
	return 0;
}
https://www.xnxx.com/video-zx1p9a0/sex_with_beautiful_girls_after_time_stands_still

https://www.xnxx.com/video-zotape0/petite_teen_babysitter_fucks_on_the_job
