#include<stdio.h>
#include<stdlib.h>
#define n 5
int x[n];
void printn(int x[])
{
    for(int i=0;i<n;i++)
        printf("%d->",x[i]);
    printf("%d\n",x[0]);
}
void hamiltonian(int k,int graph[n][n],int p)
{
   
    for(int i=0;i<n;i++)
    {
        int flag=0;
        for(int j=0;j<k;j++)
        {
            if(x[j]==i || graph[x[k-1]][i]==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            if(k<n-1)
            {
                x[k]=i;
                hamiltonian(k+1,graph,p);
            }
            else if(k==n-1 && graph[i][x[0]]==1)
            {
                x[k]=i;
              if(x[0]==p)
              {
                  printn(x);
              }
                return;
            }
        }
    }
    return;
}
int main()
{
    int graph[n][n]={
        {0,1,0,1,1},
        {1,0,1,0,1},
        {0,1,0,1,1},
        {1,0,1,0,0},
        {1,1,1,0,0},
    };
    int p=0;
    hamiltonian(0,graph,p);
}