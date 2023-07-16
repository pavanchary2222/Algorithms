#include<stdio.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void maxheap(int arr[],int n,int i)
{
    int l=2*i+1;
    int r=2*i+2;
    int largest=i;
    while(l<n && arr[largest]<arr[l])
        largest=l;
    while (r<n&& arr[largest]<arr[r])
    {
        largest=r;
    }
    if(largest!=i){
        swap(&arr[largest],&arr[i]);
        maxheap(arr,n,largest);
    }
    
}
void heapsort(int arr[],int n)
{
    for(int i=n/2-1;i>0;i--)
        maxheap(arr,n,i);
    for(int i=n-1;i>0;i--)
    {
        swap(&arr[0],&arr[i]);
        maxheap(arr,i,0);
    }

}
int main(){
int arr[]={9,8,7,6,5,4};
int n=6;
heapsort(arr,n);
printf("after sort\n");
for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
return 0;
}