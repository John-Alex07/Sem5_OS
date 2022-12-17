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
        P[i].flag = 0;
       }
}
void display_Process(Process *P, int n)
{
    printf("Process_ID | Arrival Time | Burst Time\n");
    for(int i = 0; i < n; i++)
       printf("    %d\t\t%d\t\t%d\n", P[i].P_id, P[i].ar_T, P[i].br_T);
}
void display(Process *P, int n)
{
    printf("Process_ID | Arrival Time| Burst Time | Completion Time | Turn Around Time | Waiting Time | Response Time\n");
    for(int i = 0; i < n; i++)
        printf("    %d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",P[i].P_id, P[i].ar_T, P[i].br_T, P[i].c_T, P[i].ta_T, P[i].w_T, P[i].r_T);
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
    
    int a_i = 0, b_i = 0;
    int min = P_a[a_i].P_id - 1;
    a_i++;
    P[min].c_T = P[min].ar_T + P[min].br_T;
    P[min].ta_T = P[min].c_T - P[min].ar_T;
    P[min].w_T = P[min].ta_T - P[min].br_T;
    P[min].r_T = P[min].w_T;
    P[min].flag = 1;
    
    int prev;
    int comp = 1;
    while(comp != n)
    {
        if(a_i == n || b_i == n)
          break;
        prev = min;
       if(P_b[b_i].ar_T <= P[min].c_T)
          {
            if(P[P_b[b_i].P_id - 1].flag == 1)
               {
                 b_i++;
                 continue;
               }
            min = P_b[b_i].P_id - 1;
            b_i++;
            P[min].c_T = P[prev].c_T + P[min].br_T;
          }
       else
        {
            if(P[P_a[a_i].P_id - 1].flag == 1)
             {
                a_i++;
                continue;
             }
           min = P_a[a_i].P_id - 1;
           a_i++;
           if(P[min].ar_T <= P[prev].c_T)
              P[min].c_T = P[prev].c_T + P[min].br_T;
            else
              P[min].c_T = P[min].ar_T + P[min].br_T;
        }
        P[min].ta_T = P[min].c_T - P[min].ar_T;
        P[min].w_T = P[min].ta_T - P[min].br_T;
        P[min].r_T = P[min].w_T;
        P[min].flag = 1; 
        comp++;
    }
   

    // display_Process(P_a, n);
    // printf("\n\n");
    // display_Process(P_b, n);
    // printf("\n\n");
    // display_Process(P, n);
    display(P, n);
      
}