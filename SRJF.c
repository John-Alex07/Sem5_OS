#include <stdio.h>
#include <stdlib.h>

typedef struct Process
{
    int P_id;
    int ar_T;
    int br_T;
    int c_T;
    int ta_T;
    int w_T;
    int r_T;
    int br_RT;
    int strt_T;
    int flag;
}Process;

void input(Process *P, int n)
{
    printf("Enter the Arrival Time and the Burst Time for the processes\n");
    for(int i = 0; i < n; i++)
       {
        P[i].P_id = i + 1;
        scanf("%d", &P[i].ar_T);
        scanf("%d", &P[i].br_T);
        P[i].br_RT = P[i].br_T;
       }
}
int comp_Burst(Process *x, Process *y)
{
    if(x->br_T == y->br_T)
         if(x->ar_T == y->ar_T)
            return x->P_id - y->P_id;
        else
            return x->ar_T - y->ar_T;
    return x->br_T - y->br_T;
}
int comp_Arrive(Process *x, Process *y)
{
    if(x->ar_T == y->ar_T)
       return x->P_id - y->P_id;
    return x->ar_T - y->ar_T;
}
int main()
{
    int n;
    printf("ENTER THE NUMBER OF PROCESSES :\n");
    scanf("%d", &n);

    Process P_b[n];
    Process P_a[n];
    Process P[n];
    input(P, n);
    
    for(int i = 0; i < n; i++)
       {
          P_a[i] = P[i];
          P_b[i] = P[i];
       }
    qsort(P_a, n, sizeof(Process), comp_Arrive);
    qsort(P_b, n, sizeof(Process), comp_Burst);
    
    int time = 0;
    int a_i = 0, b_i = 0;
    int min;
    int comp = 0;
    while(comp != n)
    {
      while(b_i < n && (P_b[b_i].ar_T > time || P_b[b_i].flag == 1))
               b_i++;
      if(b_i < n)
         {
            min = P_b[b_i].P_id;
            b_i = 0;
         }
      else
         {
            time++;
            continue;
         }
      if(P[min].br_T == P[min].br_RT)
        P[min].strt_T = time;
      time++;
      P[min].br_RT--;
      if(P[min].br_RT == 0)
      {
        P[min].c_T = time;
        P[min].ta_T = P[min].c_T - P[min].ar_T;
        P[min].w_T = P[min].ta_T - P[min].br_T;
        P[min].r_T = P[min].strt_T - P[min].ar_T;
        P[min].flag = 1;
        comp++;
      }
      else
      time++;
    }
}