#include <iostream>
using namespace std;
/*
 * Given an array that contains both positive and negative numbers , find the start and end index of
 * the subarray that achieves maximum subarray product using one pass
 * {10, -5, 6 , -10 , -6 }
 */

/*
 *	+ - + -
 */
void max_prod(int *arr, int len){
	int start_ = 0;
	int end_ = 0;
	int num_neg = 0;
	for(int i = 1; i < len; ++i){
		if(arr[i] < 0){
			num_neg++;
		}
		if(num_neg%2 == 0 || arr[i] > 0 ){
			end_ = i;
		}
		
	}
	printf("numneg is %d \n",num_neg );
	printf("The start is %d and end is %d \n", start_ , end_ );
}
int main(void){
	int arr[8] = {10, -5, 10, -5 , -5 , 6, -10, -6};
	max_prod(arr,8);
}