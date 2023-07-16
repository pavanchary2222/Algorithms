#include<stdio.h>
int min(int a,int b)
{
    return (a<b)?a:b;
}
int cc(int val[],int n,int S)
{
    if(n==0)
        return __INT_MAX__-10;
    if(S==0)
        return 0;
    if(n==1)
    {
        if(S%val[n-1]==0)
            return S/val[n-1];
        else    
            return __INT_MAX__-10;
    }
    if(val[n-1]<=S)
        return min(1+cc(val,n,S-val[n-1]),cc(val,n-1,S));
    else
        return cc(val,n-1,S);
}
int main()
{
    int val[]={1,2,3};
    int S=6,n=sizeof(val)/sizeof(val[0]);
    printf("The minimum no of ways of picking coins is:%d",cc(val,n,S));
}