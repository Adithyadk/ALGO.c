//Floyd’S Algorithm

#include <stdio.h>
#include <stdlib.h>
int n;
int count;
int min(int x,int y)
{
  if(x<y) return x;
  else return y;
}

void Floyd(int M[n][n], int n)
{
    int i,j,k,T;
    int D[n][n];
    for (i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            D[i][j]=M[i][j];
        }
    }
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            T=D[i][k];
            for(j=0;j<n;j++)
            {
                count++;
                if(D[i][j]>T)
                {
                    D[i][j]=min(D[i][j],T+D[k][j]);
                }
            }
            
        }
    }
    printf("Final Graph :\n");
    for (i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",D[i][j]);
        }
        printf("\n");
    }

}

void main()
{
    FILE*fptr =fopen("Floyd_count.txt","a");
    count=0;
    int i,j;
    printf(" Welocme \n Enter the number of Vertices : ");
    scanf("%d",&n);
    int a[n][n];
    printf(" Enter the Adjacency Matrix : \n");
    for (i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    Floyd(a,n);
    fprintf(fptr,"%d\t%d",n,count);
    fclose(fptr);
}