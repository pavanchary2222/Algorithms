#include<stdio.h>
int OMP(int arr[],int n);
void swap(int arr[],int i,int j);
void display(int arr[],int size);
void heapify(int arr[],int i,int n);
void insert(int arr[],int x,int *n);
int rmv(int arr[],int *n);
void minheap(int arr[],int n);


void swap(int arr[],int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}


void display(int arr[],int size)
{
    printf("\n");
    for(int i=0;i<size;i++){
        printf("%d\t",arr[i]);
    }
}

void heapify(int arr[],int i,int n)
{
    int smallest,left,right;
    smallest=i;
    left=2*i+1;
    right=2*i+2;
    if(arr[smallest]>arr[left] && left<n)
        smallest=left;
    if(arr[smallest]>arr[right] && right<n)
        smallest=right;
    if(smallest!=i){
        swap(arr,i,smallest);
        heapify(arr,smallest,n);
    }
}

void minheap(int arr[],int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(arr,i,n);
    }
}

int rmv(int arr[],int *n)
{
    swap(arr,0,*n-1);
    heapify(arr,0,*n-1);
    *n=*n-1;
    return arr[*n];
}

void insert(int arr[],int x,int *n)
{
    *n+=1;
    arr[*n-1]=x;
    swap(arr,0,*n-1);
    minheap(arr,*n);//Here I used min heap function because when a value which is smaller than it's left and right children it's not heapifying the whole array
}

int OMP(int arr[],int n)
{
    int sum=0,sum1=0;
    minheap(arr,n);// -> converts into minimum heap
    while(n>1){
        int l1=rmv(arr,&n);
        int l2=rmv(arr,&n);
        sum=l1+l2;
        sum1+=sum;
        insert(arr,sum,&n);
    }
    return sum1;

}



void main()
{
    int n;

    n=6;
    int arr[]={20,10,15,30,25,12};  
    printf("%d",OMP(arr,n));
}
