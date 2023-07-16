#include<stdio.h>
int a[10][10];
int Binomial(int n,int k)
{
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=i;j++)
            {
                if(k<=n){
                if(j==0||i==j)
                    a[i][j]=1;
                else
                    a[i][j]=a[i-1][j-1]+a[i-1][j];
            }
    }
    }
    return a[n][k];
}
int main(){
    int n,k;
    printf("Enter n value:");
    scanf("%d",&n);
    printf("Enter k value:");
    scanf("%d",&k);
    printf("The Binomial coefficient for %dC%d is:%d",n,k,Binomial(n,k));   
}
