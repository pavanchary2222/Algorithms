#include<stdio.h>
#define V 5
#define inf __INT_MAX__-100;
int imm_parent[V];
int findparent(int parent[],int i)
{
    while(parent[i]!=-1)
        i=parent[i];
    return i;
}
int swap(int *a,int*b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int kruskuls(int source[],int dest[],int wt[],int parent[],int E)
{
    int sum=0;
    for(int i=0;i<E;i++)
    {   
        if(findparent(parent,source[i])!=findparent(parent,dest[i]))
        {
            sum=sum+wt[i];
            parent[findparent(parent,dest[i])]=source[i];
            imm_parent[dest[i]]=source[i];
        }
    }
    printf("Source\tdestination\n");
    for(int i=0;i<V;i++)
    {
        if(parent[i]!=-1)
            printf("%d\t%d\n",parent[i],i);
    }
    return sum;
}
void sort(int source[],int dest[],int wt[],int parent[],int E)
{
    for(int i=0;i<E-1;i++)
    {
        for(int j=0;j<E-i-1;j++)
        {
            if(wt[j]>wt[j+1])
            {
                swap(&wt[j],&wt[j+1]);
                swap(&source[j],&source[j+1]);
                swap(&dest[j],&dest[j+1]);
            }
        }
    }
    printf("\nThe max weight for tarvesal is:%d\n",kruskuls(source,dest,wt,parent,E));
}
int main()
{
    int E=7;//  E=edges
    int source[]={0,0,1,1,1,2,3};
    int dest[]={1,2,2,3,4,4,4};
    int wt[]={2,6,8,3,5,9,7};
    
    int parent[V];
    for(int i=0;i<V;i++)
        parent[i]=-1;
    sort(source,dest,wt,parent,E);
}
