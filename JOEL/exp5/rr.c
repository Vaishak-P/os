#include<stdio.h>
void main()
{
 
  int i,j,n,t,remain,flag=0,tq;
  int wt=0,tat=0,at[10],bt[10],rt[10],pr[10];
  printf("Enter Number of Process:\t ");
  scanf("%d",&n);
  remain=n;
  printf("Enter Arrival Time >>");
  for (i = 0; i < n; i++) 
    scanf("%d", & at[i]);
  printf("Enter Burst Time >>");
  for(i=0;i<n;i++)
  {
    scanf("%d",&bt[i]);
    rt[i]=bt[i];
  }
  printf("Enter priority >>");
  for (i = 0; i < n; i++) 
    scanf("%d", & pr[i]);
  tq=2;
  for(t=0,i=0;remain!=0;)
  {
    if(rt[i]<=tq && rt[i]>0)
    {
      t+=rt[i];
      rt[i]=0;
      flag=1;
    }
    else if(rt[i]>0)
    {
      rt[i]-=tq;
      t+=tq;
    }
    if(rt[i]==0 && flag==1)
    {
      remain--;
      wt+=t-at[i]-bt[i];
      tat+=t-at[i];
      flag=0;
    }
    if(i==n-1)
      i=0;
    else if(at[i+1]<=t)
      i++;
    else
      i=0;
  }
  printf("Process     ArrivalTime     BurstTime     Priority\n");
    
    for (i = 0; i < n; i++) {
        printf("   P%d     \t%d     \t\t%d      \t\t%d\n", i+1,
               at[i], bt[i], pr[i]);
    }
  printf("\nAverage Waiting Time= %f\n",wt*1.0/n);
  printf("Avg Turnaround Time = %f\n",tat*1.0/n);
}
