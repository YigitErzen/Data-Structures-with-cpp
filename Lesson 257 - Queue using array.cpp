#include<iostream>
using namespace std;

struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(Queue *q,int size){
    q->size=size;
    q->front=q->rear=-1;
    q->Q=new int[size];
};

void enqueue(Queue *q,int data){
    if(q->rear==q->size-1){
        cout<<"The queue is full"<<endl;
    }
    else{
        q->rear++;
        q->Q[q->rear]=data;
        if(q->front==-1){
            q->front=0;
        }
    }
}

void dequeue(Queue *q){
    if(q->front ==-1 || q->front>q->rear){
        cout<<"Queue is empty"<<endl;
    }
    else{
        q->front++;
    }
}

void display(Queue *q){
    for(int i=q->front;i<=q->rear;i++){
        cout<<q->Q[i]<<endl;
    }
}

int main(){
    Queue q;
    create(&q,5);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    enqueue(&q,50);
    enqueue(&q,60);
    display(&q);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    cout<<"after dequeue"<<endl;
    display(&q);
    dequeue(&q);
    dequeue(&q);
    return 0;
}