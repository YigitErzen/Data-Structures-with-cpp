#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int d) : data(d), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() : head(nullptr) {}

    // Array'den liste oluştur
    void create(int A[], int n) {
        if (n == 0) return;

        head = new Node(A[0]);
        Node* last = head;

        for (int i = 1; i < n; i++) {
            Node* t = new Node(A[i]);
            last->next = t;
            last = t;
        }
    }

    // Yazdır
    void display() {
        Node* p = head;
        while (p) {
            cout << p->data << " -> ";
            p = p->next;
        }
        cout << "NULL" << endl;
    }

    // Yöntem 1: Array kullanarak reverse
    void reverseArray() {
        if (!head) return;

        int n = count();
        int* A = new int[n];

        // Array'e kopyala
        Node* p = head;
        for (int i = 0; i < n; i++) {
            A[i] = p->data;
            p = p->next;
        }

        // Tersten geri yaz
        p = head;
        for (int i = n - 1; i >= 0; i--) {
            p->data = A[i];
            p = p->next;
        }

        delete[] A;
    }

    // Yöntem 2: İteratif (3 pointer) - EN İYİ!
    void reverseIterative() {
        Node* p = head;
        Node* q = nullptr;
        Node* r = nullptr;

        while (p) {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }

        head = q;
    }

    // Yöntem 3: Recursive
    void reverseRecursive() {
        head = reverseRecursiveHelper(head);
    }

    // Liste uzunluğu
    int count() {
        int c = 0;
        Node* p = head;
        while (p) {
            c++;
            p = p->next;
        }
        return c;
    }

    // Destructor (belleği temizle)
    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

private:
    // Recursive helper
    Node* reverseRecursiveHelper(Node* p) {
        if (!p || !p->next) return p;

        Node* newHead = reverseRecursiveHelper(p->next);
        p->next->next = p;
        p->next = nullptr;

        return newHead;
    }
};

int main() {
    int A[] = { 10, 20, 30, 40, 50 };

    // Test 1: Array Method
    cout << "=== Test 1: Array Method ===" << endl;
    LinkedList list1;
    list1.create(A, 5);
    cout << "Orjinal:  ";
    list1.display();
    list1.reverseArray();
    cout << "Reversed: ";
    list1.display();
    cout << endl;

    // Test 2: Iterative Method (EN İYİ!)
    cout << "=== Test 2: Iterative Method ===" << endl;
    LinkedList list2;
    list2.create(A, 5);
    cout << "Orjinal:  ";
    list2.display();
    list2.reverseIterative();
    cout << "Reversed: ";
    list2.display();
    cout << endl;

    // Test 3: Recursive Method
    cout << "=== Test 3: Recursive Method ===" << endl;
    LinkedList list3;
    list3.create(A, 5);
    cout << "Orjinal:  ";
    list3.display();
    list3.reverseRecursive();
    cout << "Reversed: ";
    list3.display();

    return 0;
}