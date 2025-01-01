#include<stdio.h>
#include<stdbool.h>
#define MAX_VERTICES 100
void dfs(int graph[MAX_VERTICES][MAX_VERTICES],int vertex,bool visited[MAX_VERTICES],int numvertices)
{
printf("%d",vertex);
visited[vertex]=true;
for(int i=0;i<numvertices;++i)
{
if(graph[vertex][i]==1&&!visited[i])
{
dfs(graph,i,visited,numvertices);
}
}
}
int main()
{
int numvertices;
printf("enter the number of vertices:");
scanf("%d",&numvertices);
int graph[MAX_VERTICES][MAX_VERTICES];
printf("enter the adjancency matrix:\n");
for(int i=0;i<numvertices;++i)
{
for(int j=0;j<numvertices;++j)
{
scanf("%d",&graph[i][j]);
}
}
bool visited[MAX_VERTICES];
for(int i=0;i<numvertices;++i)
{
visited[i]=false;
}
printf("DFS traversal:");
dfs(graph,0,visited,numvertices);
return 0;
}
