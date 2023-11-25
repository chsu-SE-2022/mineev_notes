#include <iostream>
#include <string>
#include <Time.h>
using namespace std;
struct Stack {
	int top;
	int* data;
};

void initStack(Stack& st, int capacity) {
	st.data = new int[capacity];
	st.top = -1;
}

void push(Stack& st, int value) {
	st.data[++st.top] = value;
}

int pop(Stack& st) {
	return st.data[st.top--];
}

void nullStack(Stack& st) {
	st.top = -1;
}

bool empty(Stack& st) {
	return st.top == -1;
}

void showStack(Stack& st, int top) {
	for (int i = top; i > -1; i--)
		cout << i << " " << st.data[i] << endl;
}

struct Queue {
	int head, tail, size;
	int* data;
};
void nullQueue(Queue& q) {
	q.head = 0, q.tail = q.size - 1;
}
void initQueue(Queue& q, int capacity) {
	q.size = capacity + 1;
	q.data = new int[q.size];
	nullQueue(q);
}
int next(Queue& q, int n) {
	return (n + 1) % q.size;
}
bool empty(Queue& q) {
	return next(q, q.tail) == q.head;
}
void add(Queue& q, int value) {
	if (next(q, next(q, q.tail)) == q.head) {
		cout << "Queue is overflow" << endl;
	}
	else
	{
		q.tail = next(q, q.tail);
		q.data[q.tail] = value;
	}
}
void showQueue(Queue& q) {
	if (empty(q)) { cout << "Queue is empty" << endl; }
	else {
		int i = q.head;
		while (i != q.tail + 1) {
			cout << q.data[i] << " ";
			i = next(q, i);
		} cout << endl;
	}
}


int main() {
	Stack st1, st2;
	Queue q1;

	initStack(st1, 100);
	initQueue(q1, 100);
	initStack(st2, 100);

	srand(time(0));

	int q = rand() % 10 + 1;
	for (int i = 1; i < q; i++) {
		push(st1, rand() % 10);
	}
	for (int i = 1;i < q; i++) {
		add(q1, rand() % 10);
	}
	showStack(st1, st1.top);
	cout << endl << endl;
	showQueue(q1);

