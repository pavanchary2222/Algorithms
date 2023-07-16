#include<stdio.h>
int imm_parent[100];
int k;
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
int find_parent(int parent[],int i){
	while(parent[i]!=-1){
		i=parent[i]; 
	}
	return i;
}
int kruskul(int wt[],int source[],int dest[],int parent[],int n){
	int sum=0;
	for(int i=0;i<n;i++){
		if((find_parent(parent,source[i]))!=(find_parent(parent,dest[i]))){
			sum=sum+wt[i];
			parent[find_parent(parent,dest[i])]=source[i];
			imm_parent[dest[i]]=source[i];
		}
	}
	printf("source\tdestination\n");
	for(int i=0;i<k;i++)
	{
		if(parent[i]!=-1)
			printf("%d\t%d\n",parent[i],i);	
	}
	return sum;
}
int sort(int wt[],int source[],int dest[],int parent[],int n){//sorting the source,dest,and wt arrays simultaneously.
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(wt[j]>wt[j+1]){
				swap(&wt[j],&wt[j+1]);
				swap(&source[j],&source[j+1]);
				swap(&dest[j],&dest[j+1]);
			}
		}
	}
	printf("The min weight for traversal is-->%d",kruskul(wt,source,dest,parent,n));
}
void main(){
	// int i,n;
	// printf("Enter no of edges included:");
	// scanf("%d",&n);
	// int source[n],dest[n],wt[n];
	// for(i=0;i<n;i++){
	// 	printf("enter the  %d source , dest and weight values:",i);
	// 	scanf("%d %d %d",&source[i],&dest[i],&wt[i]);
	// }
	// printf("\nEnter the no of vertices present in the graph:");
	//int k;-->global declare.
	int source[]={0,0,1,1,1,2,3};
    int dest[]={1,2,2,3,4,4,4};
    int wt[]={2,6,8,3,5,9,7};
	int n=7;
	scanf("%d",&k);
	int parent[k];
	for(int i=0;i<k;i++){
	parent[i]=-1;//->initializing array with negative values.
	}
	sort(wt,source,dest,parent,n);
}
