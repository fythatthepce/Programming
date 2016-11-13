#include <stdio.h>
#include <stdbool.h>

void print(int a[], int st, int end){
	for(int i=st;i<=end;i++)
		printf("%d ",a[i]);
	printf("\n");
}



bool maxheap(int a[], int root, int end){
	if(root<=end){
		int left = 2 * root + 1;
		int right = 2 * root + 2;

		if(left<=end && a[left]>a[root])
			return false;
		if(right<=end && a[right]>a[root])
			return false;

		if(maxheap(a,left,end) == false || maxheap(a,right,end) == false)
			return false;
	}
	return true;
}

void isMaxHeap(int a[], int st, int end){
	print(a,0,end);
	if(maxheap(a,st,end))
		printf("--- max heap ---\n\n");
	else
		printf("--- NOT max heap ---\n\n");
}

int main(){


	// is Max Heap
	printf("\n+++ isMaxHeap +++\n");
	int h[13] ={68,54,63,44,42,55,60,13,31,39,70,48,50};
	isMaxHeap(h,0,9);
	isMaxHeap(h,0,10);
	isMaxHeap(h,0,11);
	isMaxHeap(h,2,10);
}
