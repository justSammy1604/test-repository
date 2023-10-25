#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
int main()
{
    int n;
    int PID[90], AT[90], BT[90], CT[90], TAT[90], WT[90];
    float avg_wait = 0,avg_tat = 0;
    int F[90],st=0,tot=0;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    for(int i=0 ;i<n;++i) 
    {
        printf("Enter Process Number %d Arrival Time ",i+1 );
        scanf("%d",&AT[i]);
        printf("Enter Process Number %d Burst Time ", i + 1);
        scanf("%d", &BT[i]);
        PID[i]=(i+1);//process id is process no.
        F[i] = 0;
    }
    bool A = true;
    while(true)
    {
        int c=n,min=999;
        if (tot==n)
        break;
        for(int i=0; i<n; i++)
        {
            if((AT[i] <= st) && (F[i] == 0) && (BT[i] < min))
            {
                min=BT[i];
                c=i;
            }
        }
        if(c == n)
        st++;
        else
        {
            CT[c] = st+BT[c];
            st+=BT[c];
            TAT[c] = CT[c]-AT[c];
            WT[c] = TAT[c] - BT[c];
            F[c] = 1;
            tot++;
        }
    }
    //printing result
    printf("\nProcess ID \tArrival time \tBurst time \tComplete Time \tTurn Around \tWaiting Time\n");
    for (int i = 0; i < n; i++)
    {
        avg_wait+=WT[i];
        avg_tat+=TAT[i];
        printf("\n%d \t\t%d \t\t%d \t\t%d \t\t%d \t\t%d\n\n",PID[i],AT[i],BT[i],CT[i],TAT[i],WT[i]);
    }
    avg_tat = (float)avg_tat/n;
    avg_wait = (float)avg_wait / n;
    printf("The Average Turn Around Time is %f\n",avg_tat);
    printf("The Average Waiting Time is %f\n" ,avg_wait); 
    return 0;
}