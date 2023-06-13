#include<stdio.h>
#include<stdlib.h>
struct process
{
	int pid,at,wt,tat,bt,ct,bt_print,scheduled;
}p[20],temp;

int n,tq;
float total_wt,total_tat;
float avg_wt,avg_tat;
int time_units=0,tail=-1;
int ready_queue[20];

void push(int idx)
{
	ready_queue[++tail]=idx;
}

int pop()
{
	int idx,i;
	if(tail==-1)
	{
		return -1;
	}
	idx=ready_queue[0];
	for(i=1;i<=tail;i++)
	{
		ready_queue[i-1]=ready_queue[i];
	}
	--tail;
	return idx;
}

void display_item(int i)
{
	printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d",p[i].pid,p[i].at,p[i].bt_print,p[i].ct,p[i].tat,p[i].wt);
}

void display()
{
	int i;
	printf("Time Quantum:%d\n",tq);
	printf("Process_id\tArrival time\tBurst time\tCompletion time\tTurn around time\tWaiting time\n");
	for(i=0;i<n;i++)
	{
		display_item(i);
		printf("\n");
	}
	printf("\nAverage WT:%f",avg_wt);
	printf("\nAverage TAT:%f",avg_tat);
	printf("\n");
}
	
void swap(int i,int j)
{
	temp=p[i];
	p[i]=p[j];
	p[j]=temp;
}

void atSort()
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(p[j].at>p[j+1].at)
			{
				swap(j,j+1);
			}
		}
	}
}
void pidSort()
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(p[j].pid>p[j+1].pid)
			{
				swap(j,j+1);
			}
		}
	}
}

int execute(int i)
{
	int time=0;
	if(p[i].bt>tq)
	{
		time=tq;
		time_units+=time;
	}
	else
	{
		time=p[i].bt;
		time_units+=time;
		p[i].ct=time_units;
		p[i].tat=p[i].ct-p[i].at;
		p[i].wt=p[i].tat-p[i].bt_print;
		total_tat+=p[i].tat;
		total_wt+=p[i].wt;
	}
	p[i].bt=p[i].bt-time;
	return time;
}

void add_newly_arrived_tasks(int last_executed)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(p[i].bt==0)
		{
			continue;
		}
		if(p[i].scheduled==1)
		{
			continue;
		}
		if(p[i].at<=time_units)
		{
			push(i);
			p[i].scheduled=1;
		}
	}
}

void rr()
{
	int current_task,time;
	atSort();
	push(0);
	p[0].scheduled=1;
	while(1)
	{
		current_task=pop();
		if(current_task==-1)
		{
			break;
		}
		time=execute(current_task);
		add_newly_arrived_tasks(current_task);
		if(p[current_task].bt>0)
		{
			push(current_task);
		}
	}
	avg_tat=total_tat/n;
	avg_wt=total_wt/n;
	pidSort();
	printf("\nRR:\n");
	display();
}
	
int main()
{
	int i;
	printf("\nEnter number of processes:");
	scanf("%d",&n);
	printf("Enter time quantum:");
	scanf("%d",&tq);
	for(i=0;i<n;i++)
	{
		p[i].pid=i+1;
		printf("Enter the arrival time:");
		scanf("%d",&p[i].at);
		printf("Enter the burst time:");
		scanf("%d",&p[i].bt_print);
		p[i].bt=p[i].bt_print;
	}
	rr();
}
