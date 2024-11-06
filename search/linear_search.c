#include<stdio.h>
int linear(int *a,int m, int n){
	for(int i = 0;i<n;i++){
		if(a[i]==m){
			return i;
		}
	}
	return -1;
}
int main()
{
	int arr[100],n,m;
	printf("Enter size of array : ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("\nEnter %d element to insert : ",i+1);
		scanf("%d",&arr[i]);
	}
	printf("\nEnter element to search :");
	scanf("%d",&m);
	int result=linear(arr,m,n);
	if(result==-1){
		printf("\nElement not found ");
	}
	else{
		printf("\nElement found at %d position ",result+1);
	}
	return 0;
}
