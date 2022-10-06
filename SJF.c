#include <stdio.h>
#include <stdlib.h>

typedef struct Process
{
    int p_id;
    int ar_T;
    int br_T;
    int c_T;
    int ta_T;
    int w_T;
    int r_T;
}Process;

void input(Process *P, int n)
{
    printf("Enter the Arrival Time and the Burst Time of the Processes :\n");
    for(int i = 0; i < n; i++)
    {
        P[i].p_id = i+1;
        scanf("%d", &P[i].ar_T);
        scanf("%d", &P[i].br_T);
    }
}

void display(Process *P, int n)
{
    printf("Process_ID   Arrival Time   Burst Time   Completion Time  TurnAround Time  Waiting Time  Response Time\n");
    for(int i = 0; i < n; i++)
        printf("   %d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", P[i].p_id, P[i].ar_T, P[i].br_T, P[i].c_T, P[i].ta_T, P[i].w_T, P[i].r_T);
}
int comp(Process *x, Process *y)
{
    if(x->br_T == y->br_T)
       return x->ar_T - y->ar_T;
    return x->br_T - y->br_T; 
}
int main()
{
    int n;
    printf("Enter the number of processes :\n");
    scanf("%d", &n);
    Process P[n];
     
     input(P, n);

     qsort(P, n, sizeof(Process), comp);

     P[0].c_T = P[0].ar_T + P[0].br_T;
     P[0].ta_T = P[0].c_T - P[0].ar_T;
     P[0].w_T = P[0].ta_T - P[0].br_T;
     P[0].r_T = 0;

     for(int i = 1; i < n; i++)
     {
        if(P[i-1].c_T < P[i].ar_T)
           P[i].c_T = P[i].ar_T + P[i].br_T;
           else
           P[i].c_T =  P[i-1].c_T + P[i].br_T;
        P[i].ta_T = P[i].c_T - P[i].ar_T;
        P[i].w_T = P[i].ta_T - P[i].br_T;
        P[i].r_T = P[i-1].c_T - P[i].ar_T;
     }
     display(P, n);

}