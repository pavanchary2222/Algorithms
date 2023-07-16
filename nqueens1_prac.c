#include<stdio.h>
#include<stdlib.h>
#define n 5
int x[n];
int print( int board[n])
{
    for(int i=0;i<n;i++)
        printf("%d->",board[i]);
    printf("\n");
}
void hamiltonian(int k,int graph[][n])
{
    for(int j=0;j<n;j++)
    {
        int flag=0;
        for(int i=0;i<k;i++)
        {
            if(x[i]==j || graph[x[k-1]][i]==0){
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            if(k<n-1)
            {
            x[k]=j;
            hamiltonian(k+1,graph);
            }
            else if(k==n-1)
            {
                print(x);
                return;
            }
        }
    }
}
int main()
{
    int graph[][n]={
        {0,1,1,1,1},
        {1,0,1,1,1},
        {1,1,0,1,1},
        {1,1,1,0,0},
        {1,1,1,0,0}
    };
    hamiltonian(0,graph);
}   