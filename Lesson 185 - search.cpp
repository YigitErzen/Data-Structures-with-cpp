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

Node* Lsearch(Node* p, int key) {
	while (p != nullptr) {
		if (p->data == key)
			return p;
		p = p->next;
	}
	return nullptr;
}

Node* RLsearch(Node* p, int key) {
	if (p == nullptr) {
		return nullptr;
	}
	if (key == p->data)
		return p;
	return RLsearch(p->next, key);
}

int main() {

	Node* temp;

	int array[] = { 10,20,30,40,50 };

	int n = sizeof(array) / sizeof(array[0]);

	Node* head = create(array, n);

	temp = RLsearch(head, 34);

	if (temp)
		cout << "Key is found: " << temp->data << endl;
	else
		cout << "Key not found" << endl;


	
	return 0;
}