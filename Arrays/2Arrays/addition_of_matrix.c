#include<stdio.h>
int main(){
	int m1[][3]={{1,2,3},{4,5,6},{7,8,9}},m2[][3]={{10,20,30},{40,50,60},{70,80,90}},m3[3][3];
	printf("The matrix multiplication = \n");
	for(int i =0;i<3;i++){
		for(int j=0;j<3;j++){
			m3[i][j]=m1[i][j]+m2[i][j];
			printf("\t%d",m3[i][j]);
		}
		printf("\n");
	}
	return 0;
}
