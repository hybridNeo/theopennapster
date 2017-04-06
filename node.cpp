#include "node.h"
#include <cstdlib>
#include <iostream>
#include <map>
using namespace std;

template <typename T>
List<T>::List(){
	head = NULL;
}

template <typename T>
void List<T>::insert(T val){
	if(head == NULL){
		head = new Node<T>();
		head->data = val;
	}else{
		Node<T> *temp;
		temp = head;
		while(temp->next != NULL)
			temp = temp->next;
		Node<T> *new_node;
		new_node = new Node<T>();
		new_node->data = val;	
		temp->next = new_node;	
	}
}

template <typename T>
void List<T>::rem_dup(){
	map<T , bool >  m;
	Node<T> *n_itr, *p_itr;
	n_itr = head;

	while(n_itr != NULL){
		if(m.find(n_itr->data) != m.end()){
			Node<T> *temp;
			temp = n_itr;
			p_itr->next = n_itr->next;
			delete temp;
		}else{
			m[n_itr->data] = true;
		}

		p_itr = n_itr;
		n_itr = n_itr->next;

	}

}


template <typename T>
T List<T>::kth(int k){
	Node<T> *itr, *k_itr;
	itr = k_itr = head;
	for(int i=0; i < k;++i){
		k_itr = k_itr->next;
	}
	while(k_itr != NULL){
		itr = itr->next;
		k_itr = k_itr->next;
	}
	return itr->data;
}

template <typename T>
void List<T>::remove(int pos){
	if(pos == 1){
		Node<T> *temp;
		temp = head;
		head = head->next;
		delete temp;
	}
	int i = 0;
	Node<T> *temp;
	temp = head;
	while(i == pos-2){
		temp = temp->next;
		i++;
	}
	Node<T> *garb;
	garb = temp->next;
	temp->next = temp->next->next;
	delete garb;

}


template <typename T>
void List<T>::print_list(){
	Node<T> *temp;
	temp = head;
	while(temp != NULL){
		cout << temp->data << "\t";
		temp = temp->next;
	}
	cout << endl;
}
template class List<int>;