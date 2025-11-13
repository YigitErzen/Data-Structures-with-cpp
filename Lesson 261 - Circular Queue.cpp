#include<iostream>
using namespace std;

class CircularQueue{
    private:
    int size;
    int front;
    int rear;
    int *Q;
    public:
    CircularQueue(int sz);
    void enqueue(int data);
    void dequeue();
    void display();
};

CircularQueue::CircularQueue(int sz){
    size=sz;
    front=rear=-1;
    Q=new int[size];
}

void CircularQueue::enqueue(int data){
    if((rear+1)%size==front){
        cout<<"The Queue is full!"<<endl;
    }
    else{
        rear=(rear+1)%size;
        Q[rear]=data;
        if(front==-1)
        front=0;
        }
    }

void CircularQueue::dequeue(){
    if (front==-1){
        cout<<"Queue is empty"<<endl;
    }
    else if (front==rear){
        front=rear=-1;
    }
    else{
        front=(front+1)%size;
    }
}

void CircularQueue::display(){
    if(front==-1){
        cout<<"Queue is empty";
    }
    else{
        int i= front;
        do{
            cout<<Q[i]<<" - ";
            i=(i+1)%size;
        }while(i!=(rear+1)%size);
        cout<<endl;
    }
}


int main(){
    CircularQueue CQ(5);
    CQ.enqueue(10);
    CQ.enqueue(20);
    CQ.enqueue(30);
    CQ.enqueue(40);
    CQ.enqueue(50);
    CQ.display();
    CQ.enqueue(60);
    CQ.dequeue();
    CQ.dequeue();
    CQ.dequeue();
    cout<<"After dequeue operations:"<<endl;
    CQ.display();
    return 0;
}   