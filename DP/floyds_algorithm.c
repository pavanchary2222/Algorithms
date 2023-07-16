#include<stdio.h>
#define v 4
#define INF 99995
void floydsalgo(int a[][v])
{
    int dist[v][v];
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            dist[i][j]=a[i][j];
        }
    }


    for(int k=0;k<v;k++)
    {
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                if(dist[i][k]+dist[k][j]<dist[i][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
            }
        }
    }

    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            if(dist[i][j]==INF)
                printf("%7s","inf");
            else 
                printf("%7d",dist[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int a[v][v] = {{0,5,INF,10},
                    {INF,0,3,INF},
                    {INF,INF,0,1},
                    {INF,INF,INF,0}
    };
    floydsalgo(a);
}