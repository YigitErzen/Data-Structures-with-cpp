#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* createLinkedListFromArray(int arr[],int n) {
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

int countNodes(Node* p) {
	int count = 0;

	while (p != nullptr) {
		count++;
		p = p->next;
	}
	return count;
}



int main() {
	int array[] = { 1,2,3,4,5,6,7,8,9,10 };

	int n = sizeof(array) / sizeof(array[0]);
	
	Node* head = createLinkedListFromArray(array, n);

	cout << countNodes(head);
}