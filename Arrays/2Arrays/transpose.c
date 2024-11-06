#include<stdio.h>
void transpose(int (*a)[3])
{
	int t[3][3];
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			t[i][j]=a[j][i];
			printf("\t%d",t[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	transpose(arr);
	return 0;
}
