#include<stdio.h>
int main()
{
	int arr[]={10,20,40,100,10,10,20,10,100,90,80,70,60,40},count=0,m[10],n;
	printf("Enter number to see repeatation of number : ");
	scanf("%d",&n);
	for(int i=0;i<14;i++){
		if(arr[i]==n){
			m[count]=i+1;
			count++;
		}
	}
	printf("\nNumber occurs %d times",count);
	printf("\n");
	for(int i=0;i<count;i++)
	{
		printf("\t%d",m[i]);
	}
	return 0;
}
