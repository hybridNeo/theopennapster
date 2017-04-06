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
 *	Keep two pointers one at first array, other at second array. youll need extra memory array c 
 *  keep moving the appropriate pointer in sorted order and keep adding the element to c
 *  copy c into original array
 */
void merge(int *arr, int mid, int len){	

	if(len < 2){
		return;
	}else if(len == 2){
		if(arr[0] > arr[1]){
			int temp = arr[0];
			arr[0] = arr[1];
			arr[1] = temp;
		}
	}else{
		// 3 2 5      1
		int l = 0;
		int j = mid;
		vector<int> c;
		while( l < mid && j < len){
			if(arr[l] < arr[j]){
				c.push_back(arr[l]);
				l++;
			}
			if(arr[l] > arr[j]){
				c.push_back(arr[j]);
				j++;
			}
		}

		while(l < mid){
				c.push_back(arr[l++]);
		}
		while(j < len){
				c.push_back(arr[j++]);
		}

		
		for(int i=0; i <len; ++i){
			arr[i] = c[i];
		}
	}
	

}

/*
 *	Simple function, split array and call merge
 */
void mergesort(int *arr, int len){
	if(len > 1){
		int mid = len/2;
		mergesort(arr, mid);
		mergesort(arr+mid, len-mid);
		merge(arr, mid , len);
	}

}
int main(void){
	int arr[5] = {4,8,3,9,5};
	// 4 , 1 , 3 and 2,5
	// 4, 1 and 3 
	// 1,4 and 3
	// 1 ... .... 4
	cout << "Before \n";
	print_arr(arr, 5);
	cout << "After \n";
	mergesort(arr,5);
	print_arr(arr, 5);
}