#include<iostream>
using namespace std;

class Queue{
private:
    int size;
    int front;
    int rear;
    int *Q;
public:
    Queue(int s);
    void enqueue(int data);
    void dequeue();
    void display();
};

Queue::Queue(int s){
    size=s;
    front=rear=-1;
    Q=new int[size];
}

void Queue::enqueue(int data){
    if(rear==size-1)
        cout<<"The Queue is full"<<endl;
    else{
        rear++;
        Q[rear]=data;
        if(front==-1)
        front=0;
    }
}

void Queue::dequeue(){
    if(front ==-1 || front>rear)
    cout<<"The Queue is empty"<<endl;
    else
    front++;
}

void Queue::display(){
    cout<<"Queue: ";
    for(int i=front;i<=rear;i++){
        cout<<Q[i]<<" - ";
    }
    cout<<endl;
}

int main(){
    Queue Q1(5);
    Q1.enqueue(10);
    Q1.enqueue(20);
    Q1.enqueue(30);
    Q1.enqueue(40);
    Q1.enqueue(50);
    Q1.display();
    Q1.enqueue(60);
    Q1.dequeue();
    Q1.dequeue();
    Q1.dequeue();
    cout<<"After dequeue operations:"<<endl;
    Q1.display();
    Q1.dequeue();
    Q1.dequeue();   
    Q1.dequeue();
    return 0;
}