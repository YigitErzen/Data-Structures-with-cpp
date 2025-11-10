#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* create(int arr[], int n) {
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

void print(Node* p) {
	if (p != 0) {
		cout << p->data << endl;
		print(p->next);
	}
}

int sum(Node* p) {
	int sum = 0;
	while (p != nullptr) {
		sum += p->data;
		p = p->next;
	}
	return sum;
}

int Rsum(Node* p) {
	int sum = 0;
	if (p == nullptr)
		return 0;
	else {
		return Rsum(p->next) + p->data;
	}
}

int main() {
	int array[] = { 10,20,30,40,50 };
	int n = sizeof(array) / sizeof(array[0]);
	Node* head = create(array, n);

	print(head);
		cout << endl;
		cout << "Sum: " << sum(head) << endl;
		cout << "RSum: " << Rsum(head) << endl;
}