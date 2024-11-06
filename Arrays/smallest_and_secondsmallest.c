#include<stdio.h>
//using namespace std;
int main(){
	int arr[10],smallest,ssmallest,z;
	for(int i =0 ; i<10;i++){
		printf("Enter %d value : ",i+1);
		scanf("%d",&arr[i]);
		printf("\n");
	}
	for(int i = 0;i<10;i++){
		printf("The %d value = %d ",i+1,arr[i]);
		printf("\n");
	}
	smallest = arr[0];ssmallest =arr[1];
	//calculating smallest and second smallerst number
	for(int i=0;i<10;i++){
		if(smallest>arr[i]){
			ssmallest = smallest;
			smallest = arr[i];
			z=i;
		}
		else if(ssmallest>arr[i]){
			if(i==z){
			break;
			}
			ssmallest= arr[i];
		}
	}
	printf("\nSmallest number = %d and second smallest number = %d ",smallest,ssmallest);
	return 0;
}
