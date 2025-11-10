#include<iostream>
using namespace std;

struct Node {
	Node* prev;
	int data;
	Node* next;
};

Node* createDoublyLinkedList(int array[], int n) {
	Node* head = new Node;
	head->prev = nullptr;
	head->data = array[0];
	head->next = nullptr;
	Node* tail = head;

	for (int i = 1; i < n; i++) {
		Node* newNode = new Node;
		newNode->data = array[i];
		tail->next = newNode;
		newNode->prev = tail;
		newNode->next = nullptr;
		tail = newNode;
	}
	return head;
}

void display(Node* p) {
	while (p!=nullptr) {
		cout << p->data << endl;
		p = p->next;
	}
}

int main() {
	int array[] = { 10,20,30,40,50 };

	int n = (sizeof(array) / sizeof(array[0]));

	Node* head = createDoublyLinkedList(array, n);

	display(head);
}