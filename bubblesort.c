#include <stdio.h>
#include <stdbool.h>

void print(int a[], int st, int end){
	for(int i=st;i<=end;i++)
		printf("%d ",a[i]);
	printf("\n");
}


void bubbleSort(int a[], int n){
	int swaped = true;
	for (int last = n-1; last>0 && swaped; last--){
			swaped = false;
			for(int i=0;i<last;i++)
				if(a[i]<a[i+1]){
			 //swap successive elements
					int temp = a[i]; 
					a[i] = a[i+1];
					a[i+1] = temp;
					swaped = true;
			}
			printf("pass%d: ",n-last);
			print(a,0,4);
	}			
}





int main(){
	// Bubble Sort
	printf("+++ Bubble Sort +++\n");
	int a[5] = {7,5,8,4,3};
	bubbleSort(a,5);
}
