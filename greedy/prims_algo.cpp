//minimum spanning tree
#include<bits/stdc++.h>
using namespace std;
#define V 5
#define inf __INT_MAX__
int findindex(int keys[],bool mstset[])
{
    int min= INT_MAX,minindex;
    for(int i=0;i<V;i++)
    {
        if(mstset[i]==false&& keys[i]<min)
            min=keys[i],minindex=i;
    }
    return minindex;
}
void printMST(int parent[],int graph[][V])
{
    cout<<"Edge \tWeight\n";
    for (int i = 1; i < V; i++)
    {
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";
    }
    
}
int primsalgo(int graph[][V])
{
    int keys[V],parent[V];
    bool mstset[V];
    for(int i=0;i<V;i++)
        keys[i]=INT_MAX,mstset[i]=false;
    
        keys[0]=0;//picking the first element for intialization
        parent[0]=-1;

    for(int count=0;count<V;count++)
    {
        int u=findindex(keys,mstset);
        mstset[u]=true;
        for(int v=0;v<V;v++)
        {
            if(graph[u][v]!=inf && mstset[v]==false)
            {
                if(graph[u][v]<keys[v])
                    keys[v]=graph[u][v],parent[v]=u;
            }
        }
    }
    printMST(parent,graph);
}
int main()
{
    int graph[][V]={{inf,9,4,inf,inf},
                    {9,inf,5,2,6},
                    {4,5,inf,inf,3},
                    {inf,2,inf,inf,8},
                    {inf,6,3,8,inf}};

    primsalgo(graph);
}
