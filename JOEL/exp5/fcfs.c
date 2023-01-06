#include<stdio.h>
void calcWaitingTime(int p[],int n,int bt[], int wt[],int at[]){
	int st[]={0,0,0,0};
	wt[0]=0;
	for(int i=1;i<n;i++){
		st[i]=st[i-1]+bt[i-1];
		wt[i]=st[i]-at[i];
	}
}
void calcTurnAroundTime(int p[],int n,int bt[],int wt[],int tat[]){
	for(int i=0;i<n;i++){
		tat[i]=bt[i]+wt[i];
	}
}
void calcAverageTime(int p[],int n,int at[],int bt[],int pr[]){
	int wt[n],tat[n],twt=0,ttat=0;
	calcWaitingTime(p,n,bt,wt,at);
	calcTurnAroundTime(p,n,bt,wt,tat);
	printf("\nProcess  ArrivalTime  BurstTime  Priority");
	for(int i=0;i<n;i++){
		twt=twt+wt[i];
		ttat=ttat+tat[i];
		printf("\n  P%d",i+1);
		printf("\t     %d",at[i]);
		printf("\t\t %d",bt[i]);
		printf("\t   %d",pr[i]);
	}
	float avgwt=(float)twt/(float)n;
	float avgtat=(float)ttat/(float)n;
	printf("\n\nAverage Waiting Time = %f",avgwt);
	printf("\nAverage Turn Around Time = %f\n",avgtat);	
}
void main(){
	int n;
	printf("Enter No. of Processes >>");
	scanf("%d",&n);
	int process[n];
	for(int i=0;i<n;i++){
		process[i]=i;
	}
	printf("Enter %d arrival times >>",n);
	int arrivalTime[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arrivalTime[i]);
	}
	int numOfProcess=sizeof(process)/sizeof(process[0]);
	printf("Enter %d Burst times >>",n);
	int burstTime[n];
	for(int i=0;i<n;i++){
		scanf("%d",&burstTime[i]);
	}
	printf("Enter %d priorities >>",n);
	int priority[n];
	for(int i=0;i<n;i++){
		scanf("%d",&priority[i]);
	}
	calcAverageTime(process,numOfProcess,arrivalTime,burstTime,priority);
}


