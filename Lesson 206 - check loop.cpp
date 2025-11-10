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

bool isLoop(Node* head) {
    Node* slow = head;  // Kaplumbağa (1 adım)
    Node* fast = head;  // Tavşan (2 adım)

    do {
        slow = slow->next;
        fast = fast->next;
        fast = fast ? fast->next : fast;
    } while (slow && fast && slow != fast);

    if (slow == fast)
        return true;
    else
        return false;
}

int main() {
    int A[] = { 10, 20, 30, 40, 50 };

    Node* first = create(A, 5);

    // Loop oluştur: 50 → 30
    Node* t1 = first->next->next;           // 30
    Node* t2 = first->next->next->next->next; // 50
    t2->next = t1;  // 50'nin next'i 30'a bağlandı

    if (isLoop(first))
        cout << "Loop var!" << endl;
    else
        cout << "Loop yok!" << endl;

    return 0;
}