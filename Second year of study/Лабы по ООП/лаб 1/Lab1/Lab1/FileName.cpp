#include<iostream>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

class printer {
private:
	char* model;
	int trays, speed;
	float quality;
public:
	void print() const;
	void input(char*x1, int x2, int x3, float x4);
	void copy(printer &a);
	bool compare(const &a);
};

void printer::input(char*x1, int x2, int x3, float x4);
{
	model = new char[srtlen(x1) + 1];
	strcpy(model, x1);
	speed = x2;
	lotki = x3;

}

void printer::print() const
{
	cout << "Model:" << model << endl;
	cout << "Speed:" << speed << endl;
	cout << "Trays:" << trays << endl;
	cout << "Quality:" << quality << endl;
	cout << endl;

}


