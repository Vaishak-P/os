#include<stdio.h>
int main() 
{
    int bt[10],at[10],p[10],wt[10],tat[10],pr[10],i,j,n,total=0,pos,temp;
    float avg_wt,avg_tat;
    printf("Enter Total Number of Process:");
    scanf("%d",&n);
    printf("Enter Arrival Time >>");
    for(i=0;i<n;i++)
        scanf("%d",&at[i]);
    printf("Enter Burst Time >>");
    for(i=0;i<n;i++)
        scanf("%d",&bt[i]);
    printf("Enter Priority:");
    for(i=0;i<n;i++){
        scanf("%d",&pr[i]);
        p[i]=i+1;
    }
    for(i=0;i<n;i++){
        pos=i;
        for(j=i+1;j<n;j++){
            if(pr[j]<pr[pos])
                pos=j;
        }
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    wt[0]=0;
    for(i=1;i<n;i++){
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
    avg_wt=(float)total/n;
    total=0;
    
    printf("Process     ArrivalTime     BurstTime     Priority\n");
    for (i = 0; i < n; i++) {
        printf("   P%d     \t%d     \t\t%d      \t\t%d\n", i+1,
               at[i], bt[i], pr[i]);
    }
    for(i=0;i<n;i++){
        tat[i]=bt[i]+wt[i];
        total+=tat[i];
    }
    avg_tat=(float)total/n;
    printf("Average Waiting Time >> %f",avg_wt);
    printf("\nAverage Turnaround Time >> %f\n",avg_tat);
 
return 0;
}

