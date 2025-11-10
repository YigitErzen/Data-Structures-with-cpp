#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* LinkedListFromArray(int array[], int n) {
	Node* head = new Node;
	head->data = array[0];
	head->next = nullptr;
	Node* tail = head;

	for (int i = 1; i < n; i++) {
		Node* newNode = new Node;
		newNode->data = array[i];
		newNode->next = nullptr;
		tail->next = newNode;
		tail = newNode;
	}
	return head;
}

int countOfNodes(Node* p) {
	int count = 0;
	while (p!= 0) {
		count++;
		p = p->next;
	}
	return count;
}

void insertLast(Node*& head, int data) {
	Node* tail = head;

	while (tail->next != nullptr) {
		tail = tail->next;
	}

	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = nullptr;
	tail->next = newNode;
}

void display(Node* p) {
	while (p != 0) {
		cout << p->data << endl;
		p = p->next;
	}
}
int main() {

	int array[] = {10,20,30,40,50};

	int n = (sizeof(array) / sizeof(array[0]));


	Node* head = LinkedListFromArray(array, n);

	display(head);

	insertLast(head, 60);
	display(head);


	return 0;

}