#include <stdio.h>
#include <stdlib.h>

int stringMatching(char T[], char P[], int M, int N)
{
    int count = 0;
    for (int i = 0; i <= N - M; i++)
    {
        int j = 0;
        while ((j < M) && (P[j] == T[i + j]))
        {
            count++;
            j++;
        }
        if (j == M)
            return count;
        count++;
    }
    return count;
}

void main()
{
    int count1, count2, N = 1000, M = 1;
    char T[N];
    FILE *fp= fopen("StringMatch.txt", "a");
    for (int i = 0; i < N; i++)
    {
        T[i] = 'A';
    }
    while (M < N)
    {
        if (M == 1) M *= 100;
        else M += 100;
        char P[M];
        for (int i = 0; i < M; i++)
        {
            P[i] = 'A';
        }
        count1 = stringMatching(T, P, M, N);
        fprintf(fp, "%d\t %d\t\t", M, count1);
        P[M - 1] = 'B';
        count2 = stringMatching(T, P, M, N);
        fprintf(fp, "%d\t%d\t\n", M, count2);
    }
    fclose(fp);
    system("gnuplot > load 'string_plot1.txt'");
    system("gnuplot > load 'string_plot2.txt'");
}
