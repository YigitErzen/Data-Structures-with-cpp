#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Baştan sil
void deleteHead(Node*& head) {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Sondan sil
void deleteTail(Node*& head) {
    if (!head) return;
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next) temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
}

// Index'e göre sil
void deleteAt(Node*& head, int index) {
    if (!head) return;
    if (index == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    for (int i = 0; i < index - 1 && temp->next; i++) {
        temp = temp->next;
    }
    if (!temp->next) return;
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

// Değere göre sil
void deleteValue(Node*& head, int value) {
    if (!head) return;
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    while (temp->next && temp->next->data != value) {
        temp = temp->next;
    }
    if (!temp->next) return;
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

// Yazdır
void print(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    // Liste: 10 → 20 → 30 → 40 → 50 → NULL
    Node* head = new Node{ 10, nullptr };
    head->next = new Node{ 20, nullptr };
    head->next->next = new Node{ 30, nullptr };
    head->next->next->next = new Node{ 40, nullptr };
    head->next->next->next->next = new Node{ 50, nullptr };

    cout << "Başlangıç: ";
    print(head);

    deleteHead(head);  // 10'u sil
    cout << "Baştan silindi: ";
    print(head);  // 20 → 30 → 40 → 50

    deleteTail(head);  // 50'yi sil
    cout << "Sondan silindi: ";
    print(head);  // 20 → 30 → 40

    deleteAt(head, 1);  // Index 1'i sil (30)
    cout << "Index 1 silindi: ";
    print(head);  // 20 → 40

    deleteValue(head, 20);  // 20'yi sil
    cout << "20 silindi: ";
    print(head);  // 40

    return 0;
}