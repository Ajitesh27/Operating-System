#include <stdio.h>
#include<stdlib.h>

int turnarroundtime(int process_no[], int n,int burst[], int wait[], int turnaround[]) {
   
   for (int i = 0; i < n ; i++)
   turnaround[i] = burst[i] + wait[i];
   return 1;
}

int waitingtime(int process_no[], int n,int burst[], int wait[], int quantum) {
   
   int remaining_burst[n];
   for (int i = 0 ; i < n ; i++)
   remaining_burst[i] = burst[i];
   int complete=0,t = 0; 
   while (complete==0) {
      complete =1;
      for (int i = 0 ; i < n; i++) {
         if (remaining_burst[i] > 0) {
            complete = 0; 
            if (remaining_burst[i] > quantum) {
               t=t+quantum;
               remaining_burst[i]=remaining_burst[i]-quantum;
            }
            
            else {
              t = t + remaining_burst[i];
              wait[i] = t - burst[i];
              remaining_burst[i] = 0;
            }
         }
      
      }
      
   }
   return 1;
}



int main() {
   
   int i,n,process_no[10],burst[10],quantum, total_wait = 0, total_turnaround = 0;
   printf("Enter number of processes : ");
   scanf("%d",&n);
   int wait[n], turnaround[n];
   for(i=0;i<n;i++){
   printf("\nEnter the name of process : ");
   scanf("%d",&process_no[i]);
   printf("Enter the burst time : ");
   scanf("%d",&burst[i]);
   }
   printf("\nEnter time quantum : ");
   scanf("%d",&quantum);
   waitingtime(process_no, n, burst, wait, quantum);
   turnarroundtime(process_no, n, burst, wait, turnaround);
   printf("Process Name\t   Burst Time\t       Waiting Time\t        Turnaround time\n");
   for (i=0; i<n; i++) {
      total_wait = total_wait + wait[i];
      total_turnaround = total_turnaround + turnaround[i];
     printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\n",i+1, burst[i], wait[i], turnaround[i]);
   }
   printf("Average waiting time = %f", (float)total_wait / (float)n);
   printf("\nAverage turnaround time = %f\n", (float)total_turnaround / (float)n);
   
   return 0;
}
