#include<stdio.h>
const int n=4;
int a[3][3];
int fsum(int freq[],int i,int j)
{
    int x=0;
    for(int l=i;l<=j;l++){
        x+=freq[l];
    }
    return  x;
}
int min(int a,int b){
    return (a<b)?a:b;
}
int optimalbstmemo(int freq[],int i,int j)
{
    if(i>j)
        return a[i][j]=0;
    else if(i==j)
        return a[i][j]=freq[i];
    else if(a[i][j]!=-1)
        return a[i][j];
    int sum=fsum(freq,i,j);
    int Min=__INT_MAX__-100,cost;
    for(int l=i;l<=j;l++)
    {
        cost=optimalbstmemo(freq,i,l-1)+optimalbstmemo(freq,l+1,j);
        Min=min(Min,cost);
    }
    return a[i][j]=(sum+Min);
}
int optimalbst(int freq[],int i,int j)
{
    if(i>j)
        return 0;
    else if(i==j)
        return freq[i];
    int sum=fsum(freq,i,j);
    int Min=__INT_MAX__-100,cost;
    for(int l=i;l<=j;l++)
    {
        cost=optimalbst(freq,i,l-1)+optimalbst(freq,l+1,j);
        Min=min(Min,cost);
    }
    return sum+Min;
} 
int main()
{
    int keys[]={10,20,30,40};
    int freq[]={8,32,54,60};
    printf("The optimal cost is:%d\n",optimalbst(freq,0,n-1));
    for (int i = 0; i <n; i++){
        for (int j=0;j<n;j++)
            a[i][j]=-1;
    }
    printf("The optimal cost is:%d\n",optimalbstmemo(freq,0,n-1));

    printf("The memorization array:\n");

    for (int i = 0; i <n; i++){
        for (int j=0;j<n;j++)
            printf("%7d",a[i][j]);
        printf("\n");
    }
}