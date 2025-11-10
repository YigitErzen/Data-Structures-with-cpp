#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void Display(Node* p) {
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

Node* create(int A[], int n) {
    Node* head = new Node;
    head->data = A[0];
    head->next = nullptr;
    Node* last = head;

    for (int i = 1; i < n; i++) {
        Node* t = new Node;
        t->data = A[i];
        t->next = nullptr;
        last->next = t;
        last = t;
    }

    return head;
}

Node* Merge(Node* first, Node* second) {
    Node* third = nullptr;
    Node* last = nullptr;

    // İlk node'u seç
    if (first->data < second->data) {
        third = last = first;
        first = first->next;
        last->next = nullptr;
    }
    else {
        third = last = second;
        second = second->next;
        last->next = nullptr;
    }

    // Kalan node'ları merge et
    while (first && second) {
        if (first->data < second->data) {
            last->next = first;
            last = first;
            first = first->next;
            last->next = nullptr;
        }
        else {
            last->next = second;
            last = second;
            second = second->next;
            last->next = nullptr;
        }
    }

    // Kalan elemanları ekle
    if (first) last->next = first;
    if (second) last->next = second;

    return third;
}

int main() {
    int A[] = { 10, 20, 40, 50, 60 };
    int B[] = { 15, 18, 25, 30, 55 };

    Node* first = create(A, 5);
    Node* second = create(B, 5);

    cout << "First list:  ";
    Display(first);

    cout << "Second list: ";
    Display(second);

    Node* merged = Merge(first, second);

    cout << "Merged list: ";
    Display(merged);

    return 0;
}