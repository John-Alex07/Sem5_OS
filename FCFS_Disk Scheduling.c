#include <stdio.h>
#include <stdlib.h>

void input(int arr[], int n)
{
    printf("Enter the disk locations:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

void display(int arr[], int n)
{
    printf("Request Sequence : \n");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int comp(int *a, int *b)
{
    return *a - *b;
}

void FCFS_DiskScheduling(int arr[], int n, int init)
{
    int p_sum = 0;
    int sum = 0;
    printf("\n");
    for(int i = 0; i < n; i++)
    {
        p_sum = abs(init - arr[i]);
        init = arr[i];
        printf("%d ", p_sum);
        sum = sum + p_sum;
    }
    printf("\nTotal Seek Count : %d", sum);
}

int main()
{
    int n;
    int init_p;

    printf("Input the number of entries :\n");
    scanf("%d",&n);
    printf("Enter the initial position of the hand:\n");
    scanf("%d", &init_p);
    int arr[n];

    input(arr, n);

    // qsort(arr, n, sizeof(int), comp);
    display(arr, n);

    FCFS_DiskScheduling(arr, n, init_p);
}