#include <stdio.h>

int graph[40][40], n, visited[40] = {0}, stack[40], stop = -1;

void createGraph()
{
	printf("No. of vertices>> ");
	scanf("%d", &n);
	printf("Enter adjacency matrix:\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &graph[i][j]);
		}
	}
}

void dfs(int v)
{
	visited[v] = 1;

	for (int i = 0; i < n; i++)
	{
		if (graph[v][i] && !visited[i])
		{
			dfs(i);
		}
	}

	stack[++stop] = v;
}

void main()
{
	int i, count = 0;

	createGraph();

	for (i = 0; i < n; i++)
	{
		if (!visited[i])
			dfs(i);
	}

	printf("Topologically Sorted Order:\n");
	for (i = n - 1; i >= 0; i--)
	{
		printf("%d-->", stack[i]);
	}
	printf("\n");
}