#include "node.h"

template <class T>
class myStack{
private:
	Node<T>* top;
public:
	void push(T elem);
	myStack();
	T pop();
	T peek();
	void print_stack();
};

