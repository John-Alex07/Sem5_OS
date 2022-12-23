#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int n, n_p;

void input(int matrix[][n])
{
    for(int i = 0; i < n_p; i++)    
    {
        printf("Process %d :\n", i+1);
        for(int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);
    }
}

void need_func(int req[][n], int alloc[][n], int need[][n])
{
    for(int i = 0; i < n_p; i++)
        for(int j = 0; j < n; j++)
            need[i][j] = fmax(req[i][j] - alloc[i][j], 0);
}

void display(int mat[][n])
{
    for(int i = 0; i < n_p; i++)
    {
        for(int j = 0; j < n; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

void safe_unsafe(int need[][n], int avail[n], int alloc[][n])
{
    int safe = 1;
    int valid[n_p];
    int p = 0;
    for(int i = 0; i < n_p; i++)
        valid[i] = 0;
    for(int i = 0; i < n_p; i++)
    {
        safe = 1;
        if(valid[i] == 1)
            continue;
        for(int j = 0; j < n; j++)
            if(avail[j] - need[i][j] < 0)
                {
                    safe = 0;
                    break;
                }
        if(safe == 1)
            {
                valid[i] = 1;
                printf("Process %d -> ", i);
                for(int j = 0; j < n; j++)
                    avail[j] = avail[j] + alloc[i][j];
                i = -1;
            }
    }
    int i = 0;
    while(valid[i] == 1)
        i++;
    if(i != n_p)
        printf("UnSAFE : DEADLOCK");
    else
        printf("SAFE");
}

int main()
{
    printf("Enter the number of resources :\n");
    scanf("%d", &n);

    int total_res[n];
    printf("Enter the Total Resources of Each :\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &total_res[i]);

    printf("Enter the number of Processes :\n");
    scanf("%d", &n_p);

    int alloc[n_p][n];
    int req[n_p][n];
    int need[n_p][n];

    printf("Enter the Number of Resources Allocated to Processes :\n");
        input(alloc);
    printf("Enter the Number of Each Resource Requested by Processes :\n");
        input(req);
    printf("Allocated :\n");
        display(alloc);
    printf("Max Required :\n");
        display(req);
        need_func(req, alloc, need);
    printf("Need :\n");
        display(need);

    int available[n];
    for(int i = 0; i < n; i++)
        {
            available[i] = 0;
            for(int j = 0; j < n_p; j++)
                available[i] = available[i] + alloc[j][i];
            available[i] = total_res[i] - available[i];
        }
    printf("Available Resource :\n");
    for(int i = 0; i < n; i++)
        printf("%d ", available[i]);
    printf("\n");
    safe_unsafe(need, available, alloc);
}