#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* lchild;
    Node* rchild;
};

class Tree {
    Node* root;

public:
    Tree() { root = nullptr; }

    void CreateTree();

    void Preorder() { Preorder(root); }
    void Preorder(Node* p);

    void Postorder() { Postorder(root); }
    void Postorder(Node* p);

    void Inorder() { Inorder(root); }
    void Inorder(Node* p);

    void Levelorder() { Levelorder(root); }
    void Levelorder(Node* p);

    int Height() { return Height(root); }
    int Height(Node* root);
};

void Tree::CreateTree() {
    Node* p;
    Node* t;
    int x;
    queue<Node*> q;

    cout << "Enter root value: ";
    cin >> x;

    root = new Node;
    root->data = x;
    root->lchild = root->rchild = nullptr;
    q.push(root);

    while (!q.empty()) {
        p = q.front();
        q.pop();

        cout << "Enter left child of " << p->data << " (-1 for none): ";
        cin >> x;

        if (x != -1) {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->lchild = t;
            q.push(t);
        }

        cout << "Enter right child of " << p->data << " (-1 for none): ";
        cin >> x;

        if (x != -1) {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->rchild = t;
            q.push(t);
        }
    }
}

void Tree::Preorder(Node* p) {
    if (p) {
        cout << p->data << " ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Inorder(Node* p) {
    if (p) {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}

void Tree::Postorder(Node* p) {
    if (p) {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << " ";
    }
}

void Tree::Levelorder(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    cout << root->data << " ";
    q.push(root);

    while (!q.empty()) {
        root = q.front();
        q.pop();

        if (root->lchild) {
            cout << root->lchild->data << " ";
            q.push(root->lchild);
        }

        if (root->rchild) {
            cout << root->rchild->data << " ";
            q.push(root->rchild);
        }
    }
}

int Tree::Height(Node* root) {
    if (root == nullptr)
        return 0;

    int x = Height(root->lchild);
    int y = Height(root->rchild);

    if (x > y)
        return x + 1;
    else
        return y + 1;
}

int main() {
    Tree t;

    t.CreateTree();

    cout << "\nPreorder: ";
    t.Preorder();

    cout << "\nInorder: ";
    t.Inorder();

    cout << "\nPostorder: ";
    t.Postorder();

    cout << "\nLevelorder: ";
    t.Levelorder();

    cout << "\nHeight: " << t.Height() << endl;

    return 0;
}