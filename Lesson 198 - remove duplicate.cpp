#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* create(int arr[], int n) {
	if (n == 0)
		return nullptr;
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

void RemoveDuplicate(Node* p) {
	Node* q = p->next;

	while (q != nullptr) {
		if (p->data != q->data) {
			p = q;
			q = q->next;
		}
		else {
			p->next = q->next;
			delete q;  
			q = p->next;
		}
	}
}

void printList(Node* h) {
	Node* temp = h;
	while (temp != nullptr) {
		cout << temp->data << endl;
		temp = temp->next;
	}
}

int main() {
	int array[] = { 10,10,10,20,20,30,40,50,50};

	int n = sizeof(array) / sizeof(array[0]);

	Node* head = create(array, n);

	printList(head);

	RemoveDuplicate(head);

	printList(head);

	return 0;
}