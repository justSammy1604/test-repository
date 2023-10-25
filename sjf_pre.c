#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
int main()
{
    int PID[90], AT[90], BT[90], CT[90], WT[90], TAT[90], F[90], k[90];
    int i,st=0,tot=0,N;
    float avg_wait=0,avg_tat=0;
    printf("Enter the number of processes: ");
    scanf("%d",&N);
    for(i = 0 ; i < N ; i++)
    {
        PID[i] = i+1;
        printf("Enter Process Number %d Arrival Time  ",i + 1);
        scanf("%d",&AT[i]);
        printf("Enter Process Number %d Burst Time  ", i + 1);
        scanf("%d", &BT[i]);
        k[i]=BT[i];
        F[i] = 0;
    }
    while (true)
    {
        int min=99,C=N;
        if(tot == N)
        break;

        for(int i=0; i<N; i++)
        {
            if((AT[i] <= st) && (F[i] == 0) && (BT[i] < min))
            {
                min=BT[i];
                C=i;
            }
        }
        if(C==N)
        st++;
        else
        {
            BT[C]--;
            st++;
            if(BT[C] == 0)
            {
                CT[C]=st;
                F[C]=1;
                tot++;
            }

        }
    }
    for(int i=0; i<N; i++)
    {
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - k[i];
        avg_tat+=TAT[i];
        avg_wait+=WT[i];
    }
    printf("\nProcess ID \tArrival time \tBurst time \tComplete Time \tTurn Around \tWaiting Time\n");
    for (int i = 0; i < N; i++)
    {
        printf("\n%d \t\t%d \t\t%d \t\t\t%d \t\t%d \t\t%d\n\n", PID[i], AT[i], k[i], CT[i], TAT[i], WT[i]);
    }
    avg_tat = (float)avg_tat / N;
    avg_wait = (float)avg_wait / N;
    printf("The Average Turn Around Time is %f\n", avg_tat);
    printf("The Average Waiting Time is %f\n", avg_wait);
    return 0;
}