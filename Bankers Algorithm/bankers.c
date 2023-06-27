#include<stdio.h>
void main()
{
	int pno,rno,i,j,k;
	int allo[20][20],max[20][20],need[20][20];
	int avail[20],flag[20],safe[20];
	int l=0;
	printf("Enter the number of process:");
	scanf("%d",&pno);
	printf("Enter the number of resources:");
	scanf("%d",&rno);
	printf("Enter the allocation matrix:\n");
	for(i=0;i<pno;i++)
	{
		for(j=0;j<rno;j++)
		{
			scanf("%d",&allo[i][j]);
		}
	}
	printf("Enter the max matrix:\n");
	for(i=0;i<pno;i++)
	{
		for(j=0;j<rno;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
	printf("Enter the availability\n");
	for(i=0;i<rno;i++)
	{
		scanf("%d",&avail[i]);
	}
	for(i=0;i<pno;i++)
	{
		for(j=0;j<rno;j++)
		{
			need[i][j]=max[i][j]-allo[i][j];
		}
	}
	printf("The need matrix:\n");
	for(i=0;i<pno;i++)
	{
		for(j=0;j<rno;j++)
		{
			printf("%d ",need[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<pno;i++)
	{
		flag[i]=0;
	}
	for(k=0;k<pno;k++)
	{
		for(i=0;i<pno;i++)
		{
			if(flag[i]==0)
			{
				int f=0;
				for(j=0;j<rno;j++)
				{
					if(need[i][j]>avail[j])
					{
						f=1;
						break;
					}
				}
				if(f==0)
				{
					safe[l]=i;
					l++;
					for(int m=0;m<rno;m++)
					{
						avail[m]+=allo[i][m];
						flag[i]=1;
					}
				}
			}
		}
	}
	int f=1;
	for(i=0;i<pno;i++)
	{
		if(flag[i]==0)
		{
			f=0;
			printf("Sytem is not safe\n");
			break;
		}
	}
	if(f==1)
	{
		printf("The given system is safe\n");
		printf("The sequence is:");
		for(i=0;i<pno;i++)
		{
			printf("P%d",safe[i]);
			if((i+1)<pno)
			{
				printf("->");
			}
		}
	}
}
