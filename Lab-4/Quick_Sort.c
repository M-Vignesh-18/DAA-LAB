#include<stdio.h>
#define MAX 100
void swap(int *a,int *b){
	int temp= *a;
	*a=*b;
	*b=temp;
}
int partitioning(int arr[],int low,int high){
	int i=low-1;int j;
	int pivot=arr[high];
	for(j=low;j<high;j++){
		if(arr[j]<=pivot){
			i++;
			swap(&arr[j],&arr[i]);
		}
	}
	i++;
	swap(&arr[high],&arr[i]);
	return i;
}
void quicksort(int arr[],int low,int high){
	if(low<high){
	int mid=partitioning(arr,low,high);
	
		quicksort(arr,low,mid-1);
		quicksort(arr,mid+1,high);
	}
}
void main(){
	int i,n,arr[MAX];
	printf("Enter no. of Element: ");
	scanf("%d",&n);
	printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
	printf("\n");
	quicksort(arr,0,n-1);
	printf("the element after sorting\n");
	for(i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
}
