#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
int main()
{
    int i,j,k,q,sum=0;
    int N,PID[90],WT[90],BT[90],TAT[90],A[90];
    printf("Enter the number of processes: ");
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        printf("Enter the Burst Time for %d ",i + 1);
        scanf("%d",&BT[i]);
    }
    printf("Enter the Time Quantum: ");
    scanf("%d",&q);
        //initializing array with burst time values in ascending order
        for (int i = 0; i < N; i++)
        {
            A[i] = BT[i];
        }
        for (int i = 0; i < N; i++)
        {
            WT[i] = 0;
        }
        do
        {
            for (int i = 0; i < N; i++)
            {
                /* code */
                if(BT[i] > q)
                {
                    BT[i]-=q;
                for (int j = 0; j < N; j++)
                {
                    if((j!=i) && BT[j]!=0)
                    WT[j]+=q;
                }
                }
                else
                {
                    for (int j = 0; j < N; j++)
                    {
                        if((j!=i) && (BT[j]!=0))
                        WT[j]+=BT[i];
                    }
                    BT[i] = 0;
                    
                }
            }
            sum=0;
            for (int k = 0; k < N; k++)
                sum+=BT[k];

        }
        while (sum!=0);
        for (int i = 0; i < N; i++)
        {
            TAT[i] = WT[i] + A[i];
        }
        
        printf("\nProcess \tBurst Time \tWaiting Time \t Turn Around");
        for (int i = 0; i < N; i++)
        {
            printf("\n%d \t\t%d \t\t%d \t\t%d\n\n", PID[i], A[i], WT[i], TAT[i]);
        }
        float avg_wait_time=0;
        float avg_tat=0;
        for (int j = 0; j < N; j++)
        {
            avg_wait_time+=WT[j];
        }
        for (int j = 0; j < N; j++)
        {
            avg_tat += TAT[j];
        }
        printf("Average Waiting Time is %f \n", (avg_wait_time/N));
        printf("Average Turn Around Time is %f " ,(avg_tat/N));
}