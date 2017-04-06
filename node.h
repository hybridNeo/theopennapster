template <typename T> 
class Node{
public:
	T data;
	Node* next;

};

template <typename T>
class List{
private:
	Node<T> *head;
public:
	List();
	void insert(T elem);
	void remove(int pos);
	void rem_dup();
	T kth(int k);
	void print_list();
};