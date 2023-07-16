#include<stdio.h>
#define V 5
#define inf __INT_MAX__-100
int findindex(int dist[],int visit[])
{
    int min=__INT_MAX__-100,minindex;
    for(int i=0;i<V;i++)
    {
        if(visit[i]==0 && dist[i]<min)
        {
            min=dist[i];
            minindex=i;
        }
    }
    return minindex;
}
void prims(int graph[V][V],int parent[],int visit[],int dist[])
{
    dist[0]=0;
    parent[0]=-1;

    for(int i=0;i<V;i++)
    {
        int in=findindex(dist,visit);
        visit[in]=1;
        for(int j=0;j<V;j++)
        {
            if(graph[in][j]!=inf && visit[j]!=1)
            {
                if(dist[j]>graph[in][j]){
                    dist[j]=graph[in][j];
                    parent[j]=in;
                }
            }
        }
    }

    printf("edge\tweight\n");
    for(int i=0;i<V;i++)
    {
        printf("%d\t%d\t%d\n",parent[i],i,dist[i]);
    }
}
int main()
{
    int graph[V][V]={{0,2,6,inf,inf},
                     {2,0,8,3,5},
                     {6,8,0,inf,9},
                     {inf,3,inf,inf,7},
                     {inf,5,9,7,0}};
    int parent[V],visit[V],dist[V];
    for(int i=0;i<V;i++)
        parent[i]=-1,visit[i]=0,dist[i]=inf;
    prims(graph,parent,visit,dist);
}