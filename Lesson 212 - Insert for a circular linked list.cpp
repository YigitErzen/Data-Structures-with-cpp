#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* createCircularLinkedList(int arr[], int n) {
	Node* head = new Node;
	head->data = arr[0];
	head->next = nullptr;
	Node* tail = head;


	for (int i = 1; i < n; i++) {
		Node* newNode = new Node;
		newNode->data = arr[i];
		newNode->next = nullptr;
		tail->next = newNode;
		tail = newNode;
	}
	tail->next = head;

	return head;
}

void display(Node* head) {

	Node* p = head;

	do {
		cout << p->data << endl;
		p = p->next;
	} 
	while (p != head);

}

void insert(Node*& head,int index, int x) {

	Node* newNode = new Node;
	newNode->data = x;
	newNode->next = nullptr;

	Node* tail = head;

	while (tail->next != head) {
		tail = tail->next;
	}

	if (index == 0) {
		newNode->next = head;
		tail->next = newNode;
		head = newNode;
	}
	else {
		Node* p = head;

		for (int i = 1; i < index; i++) {
			p = p->next;
		}
		newNode->next = p->next;
		p->next = newNode;
	}
}




int main() {
	int array[5] = { 10,20,30,40,50 };

	int n = (sizeof(array) / sizeof(array[0]));

	Node* head = createCircularLinkedList(array, n);

	display(head);

	insert(head, 2, 25);

	cout << "after inserted: ";
	display(head);


}

