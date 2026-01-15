#include<iostream> 
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* lchild;
    Node* rchild;

    Node(int value){
        data = value;
        lchild = nullptr;
        rchild = nullptr;
    }
};

class Tree {
private:
    Node* root;

    void Preorder(Node* p) {
        if (p) {
            cout << p->data << " ";
            Preorder(p->lchild);
            Preorder(p->rchild);
        }
    }

    void Inorder (Node* p){
        if (p) {
            Inorder(p->lchild);
            cout<<p->data<<" ";
            Inorder(p->rchild);
        }
    }

    void Postorder (Node *p){
        if (p) {
            Postorder(p->lchild);
            Postorder(p->rchild);
            cout<< p->data<< " ";
        }
    }

    void Levelorder (Node* p) {
        if (p == nullptr) return;

        queue<Node*> q;
        cout<<p->data<<" ";
        q.push(p);

        while(!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (current->lchild){
                cout<<current->lchild->data<<" ";
                q.push(current->lchild);
            }

            if (current->rchild) {
                cout << current->rchild->data << " ";
                q.push(current->rchild);
            }
        }
    }

    int Height(Node* p) {
        if (p == nullptr)
            return 0;
        
        int x = Height(p->lchild);
        int y = Height(p->rchild);
        
        if (x > y)
            return x + 1;
        else
            return y + 1;
    }

    int Count(Node* p) {
        if (p == nullptr)
            return 0;
        
        int x = Count(p->lchild);
        int y = Count(p->rchild);
        
        return x + y + 1;
    }

    int Sum(Node* p) {
        if (p == nullptr)
            return 0;
        
        int x = Sum(p->lchild);
        int y = Sum(p->rchild);
        
        return x + y + p->data;
    }

    int CountLeaf(Node* p) {
        if (p == nullptr)
            return 0;
        
        if (p->lchild == nullptr && p->rchild == nullptr)
            return 1;
        
        int x = CountLeaf(p->lchild);
        int y = CountLeaf(p->rchild);
        
        return x + y;
    }

    int CountDegree2(Node* p) {
        if (p == nullptr)
            return 0;
        
        int x = CountDegree2(p->lchild);
        int y = CountDegree2(p->rchild);
        
        if (p->lchild && p->rchild)
            return x + y + 1;
        else
            return x + y;
    }

    void deleteTree(Node* p) {
        if (p) {
            deleteTree(p->lchild);
            deleteTree(p->rchild);
            delete p;
        }
    }

public:
    Tree() {
        root = nullptr;
    }
    
    // Destructor
    ~Tree() {
        deleteTree(root);
    }

    void CreateTree() {
        Node* p;
        Node* t;
        int x;
        queue<Node*> q;

        cout<< "Enter root value: ";
        cin>>x;
        
        root = new Node (x);
        q.push(root);

        while (!q.empty()) {
        p = q.front();
        q.pop();

        cout<<"Enter left child of " << p->data << "(-1 for no node) ";
        cin>>x;

        if(x != -1) {
            t = new Node(x);
            p-> lchild = t;
            q.push(t);
        }

        cout<< "Enter right child of " << p->data << " (-1 for no node): ";
        cin>> x;
        if(x!= -1){
            t = new Node(x);
            p->rchild = t;
            q.push(t);
        }

        }
    }

    void Preorder() {
        cout << "Preorder: ";
        Preorder(root);
        cout << endl;
    }
    
    void Inorder() {
        cout << "Inorder: ";
        Inorder(root);
        cout << endl;
    }
    
    void Postorder() {
        cout << "Postorder: ";
        Postorder(root);
        cout << endl;
    }
    
    void Levelorder() {
        cout << "Level Order: ";
        Levelorder(root);
        cout << endl;
    }

    int Height() {
        return Height(root);
    }
    
    int Count() {
        return Count(root);
    }
    
    int Sum() {
        return Sum(root);
    }
    
    int CountLeaf() {
        return CountLeaf(root);
    }
    
    int CountDegree2() {
        return CountDegree2(root);
    }
};


int main() {
    Tree t;
    
    cout << "=== Creating Binary Tree ===" << endl;
    t.CreateTree();
    
    cout << "\n=== Tree Traversals ===" << endl;
    t.Preorder();
    t.Inorder();
    t.Postorder();
    t.Levelorder();
    
    cout << "\n=== Tree Properties ===" << endl;
    cout << "Height: " << t.Height() << endl;
    cout << "Total nodes: " << t.Count() << endl;
    cout << "Sum of all nodes: " << t.Sum() << endl;
    cout << "Leaf nodes: " << t.CountLeaf() << endl;
    cout << "Degree 2 nodes: " << t.CountDegree2() << endl;
    
    return 0;
}