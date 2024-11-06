#include<stdio.h>
void sort(int *a, int n){
	int low=0 ,high=9,mid=(low +high)/2;
	for(int i=0;i<10;i++){
		if(a[mid]==n){
			printf("Element is found at position : %d ",mid+1);
			break;
		}
		else if (a[mid]>n){
			high = mid;
			mid = (low +high)/2;
		}
		else if (a[mid]<n){
			low = mid+1;
			mid = (low +high)/2;
		}
		if (i==9){
			printf("!!Element not found!!");
		}
	}
}
int main(){
	int arr[]={10,20,30,40,50,60,70,80,90,100},n;
	printf("Enter number to search : ");
	scanf("%d",&n);
	sort(arr,n);
	return 0;
}
