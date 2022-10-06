#include <stdio.h>
#include <stdlib.h>

void print_Table(int ar_t[], int b_t[],int comp_T[], int p_id[], int w_T[], int ta_T[], int r_T[], int n)
{
    printf("Process_ID\tArrival Time\tBurst Time   Completion Time  Turn Around Time  Waiting Time  Response Time\n");
    for(int i = 0; i < n; i++)
        printf("  %d\t\t  %d\t\t  %d \t\t%d\t\t %d \t\t %d \t\t %d\n",p_id[i],ar_t[i],b_t[i], comp_T[i], ta_T[i], w_T[i], r_T[i]);
}
void swap(int *id)
{
    int temp = *id;
    *id = *(id+1);
    *(id+1) = temp;  
}
int main()
{
    int n;
    printf("Enter the number of processes:\n");
    scanf("%d", &n);

    int p_id[n],ar_t[n], b_t[n];
    printf("Enter the arrival time and burst time for processes :\n");
    for(int i = 0; i < n; i++)
      {
        scanf("%d %d", &ar_t[i], &b_t[i]);
        p_id[i] = i+1;
      }
    
    for(int i = 0; i < n-1; i++)
       for(int j = 0; j < (n-i)-1; j++)
       {
          if(ar_t[j] > ar_t[j+1])
             {
                swap(&p_id[j]);
                swap(&ar_t[j]);
                swap(&b_t[j]);
             }
       }

    int comp_T[n], ta_T[n], w_T[n], r_T[n];
    comp_T[0] = ar_t[0] + b_t[0];
    ta_T[0] = comp_T[0] - ar_t[0];
    w_T[0] = ta_T[0] - b_t[0];
    r_T[0] = w_T[0];

    float avg_WT = w_T[0], avg_TAT = ta_T[0];
    for(int i = 1; i < n; i++)
    {
       if(comp_T[i-1] < ar_t[i])
        comp_T[i] = b_t[i] + ar_t[i];
        else
        comp_T[i] = comp_T[i-1]+ b_t[i];
    
        ta_T[i] = comp_T[i] - ar_t[i];
        w_T[i] = ta_T[i] - b_t[i];
        r_T[i] = w_T[i];
        
        avg_WT = avg_WT + w_T[i];
        avg_TAT = avg_TAT + ta_T[i];
    }

    avg_WT = avg_WT/n;
    avg_TAT = avg_TAT/n;

    printf("\n");
    printf("\n");
    print_Table(ar_t,b_t,comp_T, p_id,w_T,ta_T, r_T, n);
    printf("AVERAGE WAITING TIME : %.2f\nAVERAGE TURN AROUND TIME : %.2f", avg_WT, avg_TAT);
}