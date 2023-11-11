#include <iostream>
#include <string>
#include <Time.h>
using namespace std;
struct Stack1 {
	int top;
	int* data;
};

void InitStack(Stack1& st, int capacity) {
	st.data = new int[capacity];
	st.top = -1;
}

void push(Stack1& st, int value) {
	st.data[++st.top] = value;
}

int pop(Stack1& st) {
	return st.data[st.top--];
}

void nullStack(Stack1& st) {
	st.top = -1;
}

bool empty(Stack1& st) {
	return st.top == -1;
}

struct Queue {
	int head, tail, size;
	int* data;
};

void nullQueue(Queue& q) {
	q.head = 0, q.tail = q.size - 1;
}

void InitQueue(Queue& q, int capacity) {
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
		cout << "overflow" << endl;
	}
	else
	{
		q.tail = next(q, q.tail);
		q.data[q.tail] = value;
	}
}

int del(Queue& q) {
	if (empty(q))
	{
		cout << "empty" << endl;
		return 0;
	}
	else {
		int d = q.data[q, q.head];
		q.head = next(q, q.head);
		return d;
	}
}

int main() {
	srand(time(0));

	int value1, value2, tmp, a, summ = 0, k = 0;
	double n1 = rand() % 10 + 1;
	double n2 = rand() % 10 + 1;

	Stack1 st1, st2;

	Queue q;

	InitStack(st1, n1);
	InitStack(st2, n2);

	for (int i = 0; i < n1; i++) {
		value1 = rand() % 10 + 1;
		push(st1, value1);
	}

	for (int i = 0; i < n2; i++) {
		value2 = rand() % 15 + 1;
		push(st2, value2);
	}

	cout << "Stack 1: ";
	tmp = st1.top;
	while (!empty(st1)) {
		a = pop(st1);
		cout << a << " ";
	}
	st1.top = tmp;
	cout << endl;

	cout << "Stack 2: ";
	tmp = st2.top;
	while (!empty(st2)) {
		a = pop(st2);
		cout << a << " ";
	}
	st2.top = tmp;
	cout << endl;

	while (!empty(st2)) {
		a = pop(st2);
		summ += a;
	}

	st2.top = tmp;
	cout << "Sum 2nd stack = " << summ;
	cout << endl;

	InitQueue(q, n1);
	tmp = st1.top;
	while (!empty(st1)) {
		a = pop(st1);
		if (summ % a != 00) {
			add(q, a);
			k++;
		}
	}

	if (k == 0) cout << "there are no valid values";
	else {
		cout << "Queue: ";
		st1.top = tmp;
		while (!empty(q)) {
			a = del(q);
			cout << a << " ";
		}
	}
	cout << endl;
	system("pause");
	return 0;
}