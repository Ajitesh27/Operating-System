#include<stdio.h>
 int main()
{
    int i,j,n,total=0,pos,temp,burst[10],order[10],wait[10],turnaround[10];
    float avgwait,avgturnaround;
    printf("****Shortest Job First****\n");
    printf("Enter no of jobs:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter Burst Time of %d process:",i+1);
        scanf("%d",&burst[i]);
        order[i]=i+1;         
    }
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(burst[j]<burst[pos])
                pos=j;
        }
  
        temp=burst[i];
        burst[i]=burst[pos];
        burst[pos]=temp;
  
        temp=order[i];
        order[i]=order[pos];
        order[pos]=temp;
    }
    wait[0]=0;            
    for(i=1;i<n;i++)
    {
        wait[i]=0;
        for(j=0;j<i;j++)
            wait[i]=wait[i]+burst[j];
  
        total=total+wait[i];
    }
  
    avgwait=(float)total/n;      
    total=0;
  
    printf("Job\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        turnaround[i]=burst[i]+wait[i];   
        total=total+turnaround[i];
        printf("\n%d\t\t  %d\t\t    %d\t\t\t%d",order[i],burst[i],wait[i],turnaround[i]);
    }
  
    avgturnaround=(float)total/n;    
    printf("\n\nAverage Waiting Time=%f",avgwait);
    printf("\nAverage Turnaround Time=%f\n",avgturnaround);
    return 0;
}
