#include<stdio.h>
#include<stdlib.h>

float knap(int n,float c,float w[],float p[])
{
	int i;
	float tp;
	float x[n];
	for(i=0;i<n;i++)
	{
		x[i]=0;
	}
	for(i=0;i<n;i++)
	{
		if(w[i]>c)
		{
			break;
		}
		else
		{
			x[i]=1;
			tp=tp+p[i];
			c=c-w[i];
		}
	}
	if(i<n)
	{
		x[i]=c/w[i];
	}
	
	tp=tp+(x[i]*p[i]);
	
	printf("Solution Tuple:");
	for(i=0;i<n;i++)
	{
		printf("%f  ",x[i]);
	}
	printf("\n");
	printf("maximum profit=%f",tp);
}	
			
			
void main()
{
	int i,j,n;
	float max,temp;
	printf("Enter size of array:");
	scanf("%d",&n);
	float w[n],p[n],r[n];
	printf("Weight:");
	for(i=0;i<n;i++)
	{
		scanf("%f",&w[i]);
	}
	printf("Profit:");
	for(i=0;i<n;i++)
	{
		scanf("%f",&p[i]);
	}
	printf("Enter the maximum weight:");
	scanf("%f",&max);
	
	for(i=0;i<n;i++)
	{
		r[i]=p[i]/w[i];
	}
	
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(r[i]<r[j])
			{
				temp=r[j];
				r[j]=r[i];
				r[i]=temp;
					
				temp=w[j];
				w[j]=w[i];
				w[i]=temp;
				
				temp=p[j];
				p[j]=p[i];
				p[i]=temp;
			}
		}
	}
	knap(n,max,w,p);
}
