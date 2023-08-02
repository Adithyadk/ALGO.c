/* program to implement quick sort*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int beg, int end)
{
    int pivot = arr[beg];
    int i = beg, j = end + 1;

    do
    {

        do
        {
            count++;
            i++;
        } while (arr[i] < pivot);

        do
        {
            count++;
            j--;
        } while (arr[j] > pivot);
        swap(&arr[i], &arr[j]);

    } while (i < j);

    swap(&arr[i], &arr[j]);
    swap(&arr[beg], &arr[j]);

    return j;
}

void quicksort(int *arr, int beg, int end)
{
    if (beg < end)
    {
        int split = partition(arr, beg, end);
        quicksort(arr, beg, split - 1);
        quicksort(arr, split + 1, end);
    }
}

void main()
{

    int *arr, n;
    srand(time(NULL));
    FILE *f;

    f = fopen("Quick_time.txt", "w");
    n = 4;

    while (n < 1025)
    {
        arr = (int *)malloc(sizeof(int) * n);
        
        // Best case
        for (int i = 0; i < n; i++)
            *(arr + i) = 5;
        count = 0;
        quicksort(arr, 0, n - 1);
        fprintf(f, "%d\t%d\t", n, count);
        // printf("%d\t%d\n",n,count);

        // AVG case
        for (int i = 0; i < n; i++)
            *(arr + i) = rand() % n;
        count = 0;
        quicksort(arr, 0, n - 1);
        fprintf(f, "%d\t%d\t", n,count);
        // printf("%d\t%d\n",n,count);
      
        // worst case
        count = 0;
        for (int i = 0; i < n; i++)
            *(arr + i) = n-i;
        quicksort(arr, 0, n - 1);
        fprintf(f, "%d\t%d\n", n, count);
        //printf("%d\t%d\n",n,count);

        n = n * 2;
        free(arr);
    }

    fclose(f);

}