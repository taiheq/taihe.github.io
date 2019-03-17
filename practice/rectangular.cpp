// rectangular.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;

class Rect {
private:
	double l, w;
public:
	Rect(double a, double b) {
		l = a;
		w = b;
	}
	void getArea();
	void getCircum();
	int isSquare();
};
void Rect::getArea(){

		cout << "area is " << l * w << endl;

}
void Rect::getCircum() {
	cout << "circum is " << (l + w) * 2 << endl;
}
int Rect::isSquare() {
	if (l = w) 
		return 1;
	
	else
		return 0;
	
}
int main()
{
	cout << "please input length and width";
	double length, wide;
	cin >> length >>wide;
	Rect r(length, wide);
	r.getArea();
	r.getCircum();
	if (r.isSquare())
		cout << "it is square" << endl;
	else
		cout << "it is not square" << endl;

}


