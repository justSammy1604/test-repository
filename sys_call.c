
// #include <stdio.h>
// #include <utmpx.h>
// #include <time.h>

// int main(void)
// {
//     struct utmpx *n;
//     char *a;
//     int i;

//     setutxent();
//     n = getutxent();

//     while (n != NULL)
//     {
//         if (n->ut_type == USER_PROCESS)
//         {
//             printf("%-9s", n->ut_user);
//             printf("%-12s", n->ut_line);
//             a = ctime((const time_t *)&n->ut_tv.tv_sec);
//             printf(" ");
//             for (i = 4; i < 16; i++)
//                 printf("%c", a[i]);
//             printf(" ( %s )", n->ut_host);
//             printf("\n");
//         }
//         n = getutxent();
//     }

//     endutxent(); // Close utmpx file

//     return 0;
// }




#include<stdio.h>
// #include<iostream.h>
#include<string.h>
#include<sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int PID;
    PID = fork();

    if (PID<0) // Error has occurred
    {
        fprintf(stderr, "Error, Fork Failed!!\n");
        exit(-1);
    }
    else if (PID==0)
    {
        printf("I am the child. return to from fork = %d\n",PID);
        execlp("/bin/ls","lss",NULL);
    }
    else
    {
        printf("I am the parent, return from fork, child PID = %d\n",PID);
        printf("Parent Exiting!!\n");
    }
    return 0;
}
