#include<stdio.h>
#include<stdlib.h>
#define size 4
int board[size];
void printn(int board[])
{
	int i,j;
    for(i=0;i<size;i++)
        printf("\t%d",i);
        printf("\n\n");
    for(i=0;i<size;i++)
    {
        printf("%d\t",i);
        for(j=0;j<size;j++){
        if(board[i]==j)
            printf("Q\t");
        else
            printf("-\t");
        }
        printf("\n\n");
    } 
}
int issafe(int k,int j)
{
	int i;
    for(i=0;i<k;i++)
    {
        if(board[i]==j)
            return 0;
        else if(abs(k-i)==abs(j-board[i]))
            return 0;
    }
    return 1;
}
void Nqueens(int k,int n)
{
	int j;
    for(j=0;j<n;j++)
    {
        if(issafe(k,j))
        {
            board[k]=j;
            if(k==n-1)
            {
                printf("The board with Queens\n");
                printn(board);
                printf("\n\n\n");
            }
            else
                Nqueens(k+1,n);
        }
    }
}
int main()
{
    int n;
    printf("Enter the board size:");
    scanf("%d",&n);
    Nqueens(0,n);
}
