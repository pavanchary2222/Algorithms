#include<stdio.h>
void print(int array[],int len){
	int i;
//	printf("hjkl");
	for(i=0;i<len;i++){
		printf("%d ",array[i]);
	}
	printf("\n");
	return;
}
void ss(int a[],int w, int n,int rsum,int x[],int len){
	if(w==0){
		print(x,len);
		return;
	}
	if(n==0 || rsum<w){
		return;
	}
	if(a[n-1]<=w){
		x[n-1]=1;
		ss(a,w-a[n-1],n-1,rsum-a[n-1],x,len);
	}
	x[n-1]=0;
	ss(a,w,n-1,rsum-a[n-1],x,len);
}
int sum(int a[],int len){
	int i,s=0;
	for(i=0;i<len;i++){
		s+=a[i];
	}
	return s;
}
int main(){
	int n,w;
	printf("Enter the number of sums\n");
	scanf("%d",&n);
	int temp_len=n;
	printf("Enter the sums\n");
	int a[n],i,x[n];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		x[i]=0;
	}
	int rsum=sum(a,n);
	printf("Enter the weight which you have to find whether present or not\n");
	scanf("%d",&w);
	ss(a,w,n,rsum,x,temp_len);

}
