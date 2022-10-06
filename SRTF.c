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
   printf("Enter the Arrival Time and the Burst Time:\n");
   for(int i = 0; i < n; i++)
   scanf("%d %d", &P[i].ar_T, &P[i].br_T); 
}

int main()
{
    int n;
    printf("Enter the number of processes:\n");
    scanf("%d", )
}