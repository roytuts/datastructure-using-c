#include<stdio.h>

void insert(int *a, int n, int i, int k){
	int j,l;
	if(n<=i){
		printf("Insertion index must be less than size of the array");
		return;
	}
	for(j=n-2;j>=i;j--){
		a[j+1]=a[j];
	}
	a[j+1]=k;
	for(l=0;l<n;l++){
		printf("a[%d]=%d ",l,a[l]);
	}
}

main(){
	int i;
	int size=6;
	int a[6];
	for(i=0;i<size-1;i++){
		a[i]=i+100;
	}
	insert(a,size,5,135);
	return;
}
