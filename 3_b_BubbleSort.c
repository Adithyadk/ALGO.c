#include <stdio.h>
#include <stdlib.h>
int bubble(int a[], int n)
{
    int c = 0, i, j, t, f = 0;
    for (i = 0; i < n - 1; i++)
    {
        f = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            c++;
            if (a[j] > a[j + 1])
            {
                f = 1;
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
        if (f == 0)
            return c;
    }
    return c;
}
void main()
{
    int ct, i = 10, k, *a;
    FILE *f;
    ct = 0;
    f = fopen("bubcount.txt", "a");

    while (i < 40000)
    {
        if (i < 10000) i *= 10;
        else i *= 2;
        a = (int *)malloc(sizeof(int) * i);
        // Best case
        for (k = 0; k <= i; k++)
            a[k] = k;
        ct = bubble(a, i);
        printf("bestfor i: %d\tct :%d\n", i, ct);
        fprintf(f, "%d\t\t%d\t\t", i, ct);
        // Worst Case
        for (k = 0; k <= i; k++)
            a[k] = i - k;
        ct = bubble(a, i);
        printf("worstfor i: %d\tct :%d\n", i, ct);
        fprintf(f, "%d\t\t%d\n", i, ct);

    }
    fclose(f);
   
}