#include<iostream>
using namespace std;

struct Node {
	Node* prev;
	int data;
	Node* next;
};

Node* createDoublyLinkedList(int array[], int n) {

	if (n == 0) {
		return nullptr;
	}

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
	while (p != nullptr) {
		cout << p->data << endl;
		p = p->next;
	}
}

void InsertInTheDoublyLinkedList(Node*& head, int index, int data) {
	if (index < 0) {
		return;
	}

	Node* newNode = new Node;
	newNode->data = data;

	// Boş liste veya başa ekleme
	if (index == 0 || head == nullptr) {
		newNode->prev = nullptr;
		newNode->next = head;
		if (head != nullptr) {  // ✅ Null check eklendi
			head->prev = newNode;
		}
		head = newNode;
		return;
	}

	Node* p = head;
	for (int i = 1; i < index && p->next != nullptr; i++) {  // ✅ p->next kontrolü eklendi
		p = p->next;
	}

	// Sona ekleme
	if (p->next == nullptr) {
		newNode->next = nullptr;
		newNode->prev = p;
		p->next = newNode;
	}
	// Araya ekleme
	else {
		newNode->next = p->next;
		newNode->prev = p;
		p->next->prev = newNode;
		p->next = newNode;
	}
}

void DeleteFromDoublyLinkedList(Node*& head, int index) {
	// Güvenlik kontrolü
	if (head == nullptr || index < 0) {
		return;
	}

	Node* p = head;

	if (index == 0) {
		head = head->next;
		if (head) {
			head->prev = nullptr;
		}
		delete p;
	}
	else {
		// Index'e git (güvenli şekilde)
		for (int i = 0; i < index && p != nullptr; i++) {
			p = p->next;
		}

		// Eğer p null ise, index geçersiz demektir
		if (p == nullptr) {
			return;
		}

		// Önceki düğümü sonrakine bağla
		p->prev->next = p->next;

		// Eğer sonraki düğüm varsa, onu öncekine bağla
		if (p->next) {
			p->next->prev = p->prev;  // ✅ DOĞRU!
		}

		delete p;
	}
}

int main() {
	int array[] = { 10,20,30,40,50 };

	int n = (sizeof(array) / sizeof(array[0]));

	Node* head = createDoublyLinkedList(array, n);

	display(head);


	cout << "--------" << endl;
	DeleteFromDoublyLinkedList(head, 4);
	display(head);
}