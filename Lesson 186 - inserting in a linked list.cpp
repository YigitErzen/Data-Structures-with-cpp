#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* arrayToLinkedList(int arr[], int n) {
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
	return head;
}

int countOfNodes(Node* p) {
	int count = 0; 
	while (p != 0) {
		count++;
		p = p->next;
	}
	return count;
}

void display(Node* p) {
	while (p != 0) {
		cout << p->data << " ";  
		p = p->next;
	}
}

void insert(Node*& head, int value, int index) {
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = nullptr;

	if (index == 0) {
		newNode->next = head;
		head = newNode;
		return;
	}

	Node* temp = head;
	for (int i = 0; i < index - 1 && temp != nullptr; i++) {
		temp = temp->next;
	}

	if (temp == nullptr) {
		delete newNode;
		return;
	}

	newNode->next = temp->next;
	temp->next = newNode;
}

int main() {
	int array[] = { 10,20,30,40,50 };
	int n = (sizeof(array) / sizeof(array[0]));

	Node* head = arrayToLinkedList(array, n);

	cout << "Liste: ";
	display(head);
	cout << "\nNode sayisi: " << countOfNodes(head) << endl;

	insert(head, 32, 0);
	cout << "32 eklendi: ";
	display(head);

	return 0;
}