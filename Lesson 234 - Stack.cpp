#include<iostream>
using namespace std;

struct Stack {
	int size;
	int top;
	int* S;
};

void create(Stack *st) {
	cout << "enter size";
	cin >> st->size;
	st->top = -1;
	st->S = new int[st->size];
}

void display(Stack st) {
	for (int i = st.top; i>=0; i--) {
		cout << st.S[i] << endl;
	}
	cout << endl;
}

void push(Stack* st, int data) {
	if (st->top==st->size-1) {
		cout << "Stack overflow!" << endl;
	}
	else {
		st->top++;
		st->S[st->top] = data;
	}
}

int pop(Stack* st) {
	int x = -1;
	
	if (st->top==-1) {
		cout << "Stack Underflow!";
	}
	else {
		x = st->S[st->top];
		st->top--;
	}
	return x;
}

int peek(Stack st, int index) {
	int x = -1;

	if (st.top - index + 1 < 0) {
		cout << "Invalid Index" << endl;
	}
	else {
		x = st.S[st.top - index + 1];
	}

	return x;
}

bool isEmpty(Stack st) {
	return (st.top == -1);
}

bool isFull(Stack st) {
	return (st.top == st.size-1);
}

int stackTop(Stack st) {
	if (!isEmpty(st)) {
		return st.S[st.top];
	}
	return -1;
}

int main() {
	Stack st;
	create(&st);

	push(&st, 10);
	push(&st, 20);
	push(&st, 30);
	push(&st, 40);

	cout << "Peek at index 2: " << peek(st, 2) << endl;
	display(st);

	delete[] st.S;  // Belleği temizle

	return 0;
}