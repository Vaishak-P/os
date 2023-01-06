#include<stdio.h>

int main() {
  
  int sumt = 0, sumw = 0;
  int time, burst_time[10], at[10], pr[10],bt[10], sumbt= 0, small, n, i;
  printf("Enter Number of Processes : ");
  scanf("%d", & n);
  printf("Enter Arrival Time --");
  for (i = 0; i < n; i++) 
    scanf("%d", & at[i]);
  
  printf("Enter Burst Time --");
  for (i = 0; i < n; i++){
    scanf("%d", & burst_time[i]);
    bt[i]=burst_time[i];
    sumbt += burst_time[i];
  }
  printf("Enter priority --");
  for (i = 0; i < n; i++) 
    scanf("%d", & pr[i]);
  burst_time[9] = 9999;
  for (time = 0; time < sumbt;) {
    small = 9;
    for (i = 0; i < n; i++) {
      if (at[i] <= time && burst_time[i] > 0 && burst_time[i] < burst_time[small])
        small = i;
    }
    sumt += time + burst_time[small] - at[small];
    sumw += time - at[small];
    time += burst_time[small];
    burst_time[small] = 0;
  }
   printf("Process     ArrivalTime     BurstTime     Priority\n");
    
    for (i = 0; i < n; i++) {
        printf("   P%d     \t%d     \t\t%d      \t\t%d\n", i+1,
               at[i], bt[i], pr[i]);
    }
  printf("average waiting time = %f", sumw * 1.0 / n);
  printf("\naverage turnaround time = %f\n", sumt * 1.0 / n);
  return 0;
}


 

