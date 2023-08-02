#include <stdio.h>

int graph[40][40], n, visited[40]={0}, indegree[40]={0};

void createGraph(){
	printf("No. of vertices>> ");
	scanf("%d", &n);
	printf("Enter adjacency matrix:\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&graph[i][j]);
		}
	}
}

void main(){
	int i,j,count=0;
	
	createGraph();
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if (graph[j][i]) indegree[i]++;
		}
	}
	
	printf("Topologically Sorted Order:\n");
	while(count<n){
		for(i=0;i<n;i++){
			if (!visited[i] && !indegree[i]){
				printf("%d-->",i);
				visited[i]=1;
				for(j=0;j<n;j++){
					if (graph[i][j]){
						graph[i][j]=0;
						indegree[j]--;
					}
				}
				count++;
				break;
			}
		}
	}
	printf("\n");
	
}