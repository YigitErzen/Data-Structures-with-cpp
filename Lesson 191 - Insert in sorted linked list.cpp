#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Sıralı listeye ekleme (Iterative)
void insertSorted(Node*& head, int value) {
    // Yeni node oluştur
    Node* newNode = new Node{ value, nullptr };

    // DURUM 1: Liste boş
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // DURUM 2: Başa ekleme (en küçük)
    if (value < head->data) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // DURUM 3: Ortaya veya sona ekleme
    Node* current = head;
    Node* prev = nullptr;

    // Doğru pozisyonu bul
    while (current != nullptr && current->data < value) {
        prev = current;
        current = current->next;
    }

    // prev ve current arasına ekle
    prev->next = newNode;
    newNode->next = current;
}

// Yazdırma
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;

    // Sıralı ekleme
    insertSorted(head, 30);
    insertSorted(head, 10);
    insertSorted(head, 50);
    insertSorted(head, 20);
    insertSorted(head, 40);

    printList(head);  // 10 -> 20 -> 30 -> 40 -> 50 -> NULL

    return 0;
}