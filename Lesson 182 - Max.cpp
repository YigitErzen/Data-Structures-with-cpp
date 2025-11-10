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

int max(Node* p) {
	int max = p->data;

	while (p != nullptr) {
		if (p->data > max) {
			max = p->data;
		}
		p = p->next;
	}
	return max;
}

int Rmax(Node* p) {
	int x = 0;
	if (p == 0) {
		return 0;
	}
	x = Rmax(p->next);
	if (x > p->data)
		return x;
	else return p->data;

}

int main() {
	int array[] = { 70,20,50,80,20 };

	int n = sizeof(array) / sizeof(array[0]);

	Node* head = create(array, n);

	cout << "max:" << max(head) << endl;
	cout << "Rmax:" << Rmax(head);

	return 0;
}