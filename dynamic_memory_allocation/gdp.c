#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *arr,n;
	printf("Enter the number of countries : ");
	scanf("%d",&n);
	arr = (int *)malloc(sizeof(int)*n);
	for(int i=0 ; i<n;i++)
	{
		printf("Enter the GDP for %d country : ",i+1);
		scanf("%d",&arr[i]);
	}
	printf("\n");
	for(int i=0;i<n;i++)
	{
		printf("The GDP for %d country = %d\n ",i+1,arr[i]);
	}
	return 0;
}
