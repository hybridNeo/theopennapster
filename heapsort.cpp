#include <iostream>
#include <vector>
using namespace std;
void print_arr(int *arr, int len){
	for(int i=0; i < len;++i){
		cout << arr[i] << " ";
	}
	cout << endl;
}

/*
 *	find the left and right elements
 *  if either of them is larger than the root, swap it and recursively call max_heapify
 */
void max_heapify(int *arr, int len, int i){
	int l = ((i+1) * 2 )- 1;
	int r = ((i+1) * 2 );
	int largest;
	// printf("for i = %d , l is %d and r is %d \n",i,l,r );
	if(l < len && arr[l] > arr[i] ){
		largest = l;
	}
	else
		largest = i;
	if(r < len && arr[r] > arr[largest]){
		largest = r;
	}
	if(largest != i){
		int temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		max_heapify(arr,len, largest);
	}
}

/*
 *	build a heap by calling max_heapify from halfway line
 */
void build_heap(int *arr, int len){
	int i = len/2;
	while(i >= 0){
		max_heapify(arr,len,i);
		i--;
	}
}

/*
 *	First build a max heap 
 *  then replace the root with the last element and max_heapify
 *  repeat this process
 */
void heap_sort(int *arr, int len){
	build_heap(arr,len);
	// print_arr(arr,len);
	int i=len-1;
	while(i >= 0){
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		max_heapify(arr,--len,0);
		i--;
	}
}
int main(void){
	int arr[5] = {4,8,3,9,5};
	//    4
	//  8,  and 3 
	// 9,5 
	cout << "Before \n";
	print_arr(arr, 5);
	cout << "After \n";
	heap_sort(arr,5);
	print_arr(arr, 5);
}