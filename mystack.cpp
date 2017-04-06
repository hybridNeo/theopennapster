#include "mystack.h"
#include <cstdlib>
#include <iostream>
using namespace std;
template <typename T>
myStack<T>::myStack(){
	top = NULL;
}

template <typename T>
void myStack<T>::push(T val){
	if(top == NULL){

		Node<T> *temp = new Node<T>;
		top = temp;
		top->data = val;
	}else{
		Node<T> *node = new Node<T>();
		node->data = val;
		node->next = top;
		top = node;
	}
}

template <typename T>
T myStack<T>::pop(){
	if(this->top == NULL){
		return 0;
	}
	else{
		Node<T> *e = this->top;
		T elem = e->data;
		top = this->top->next;
		delete e;
		return elem;
	}
}

template <typename T>
T myStack<T>::peek(){
	if(this->top == NULL){
		return 0;
	}else{
		T elem(this->top->data);
		return elem;
	}
}

template <typename T>
void myStack<T>::print_stack(){
	Node<T> *temp = this->top;
	while(temp != NULL){
		cout << temp->data << "\t";
		temp = temp->next;
	}
	cout << endl;
}

template class myStack<int>;
