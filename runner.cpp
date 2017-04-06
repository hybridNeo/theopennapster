#include <iostream>
#include "mystack.h"
#include <iostream>
using namespace std;
int main(void){
	List<int> a;
	a.insert(1);
	a.insert(2);
	a.insert(1);
	a.insert(4);
	cout << "kth " << a.kth(3) << endl;
	a.print_list();
	a.rem_dup();
	a.print_list();
}