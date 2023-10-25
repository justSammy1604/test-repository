#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    int ID[30], BT_time[30], WT_time[30],N;
    int total=0; float avg;
    printf("Enter the number of processes: "); 
    scanf("%d",&N);
    for(int i = 0 ;i< N;i++)
    {
        printf("\n");
        printf("Enter Process ID Of Process %d\t",i+1);
        scanf("%d",&ID[i]);
        printf("Enter Burst Time of Process  %d:\t",i+1);
        scanf("%d",&BT_time[i]);
    }
    WT_time[0] = 0;
    //for calculating waiting time
    for (int i =1;i < N; i++)
    {
        WT_time[i] = WT_time[i-1]+BT_time[i-1];
        total = total+WT_time[i];
    }
    avg = (float)total/N;
    printf("\nProcess_Id \tBurst_Time \tWaiting_Time :\n");
    for(int j = 0;j < N;j++)
    {
        printf("%d \t\t %d \t\t %d\n",ID[j],BT_time[j],WT_time[j]);
    }
    printf("Total Wait Time is %d \n",total);
    printf("Average Wait Time is %f \n", avg);
    return 0;
}