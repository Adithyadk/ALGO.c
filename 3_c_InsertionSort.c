// Program to implement Insertion sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n, int *count)
{
  int i, j, temp;
  for (i = 1; i < n; i++)
  {
    temp = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > temp)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
      *(count) += 1;
    }
    if (j + 1 == i && arr[j] < temp)
    {
      *(count) += 1;
    }
    j = j + 1;
    arr[j] = temp;
  }
}

void main()
{
  int *arr, i, n = 1, count;
  srand(time(NULL));
  FILE *f;
  f = fopen("insertion_time.txt", "w");
  while (n < 40000)
  {
    if (n < 10000) n *= 10;
    else n *= 2;
    arr = (int *)malloc(sizeof(int) * n);

    // best case
    count = 0;
    for (i = 0; i < n; i++)
      arr[i] = i;
    insertionSort(arr, n, &count);
    fprintf(f, "%d\t%d\t", n, count);

    // avg case
    count = 0;
    for (i = 0; i < n; i++)
      arr[i] = rand() % n;
    insertionSort(arr, n, &count);
    fprintf(f, "%d\t%d\t", n, count);

    // worst case
    count = 0;
    for (i = 0; i < n; i++)
      arr[i] = n - i;
    insertionSort(arr, n, &count);
    fprintf(f, "%d\t%d\n", n, count);

    free(arr);
  }
  fclose(f);
  // system("gnuplot>load 'insertion_plot.txt'");
}