#pragma once

#include<iostream>
using std::istream;
using std::ostream;
class MyPoint
{
	int x;
	int y;//µãµÄ×ø±ê
public:
	MyPoint();
	void SetPoint(int x, int y);
	MyPoint operator+(int i)const;
	MyPoint operator+(MyPoint& const other)const;
	/*friend MyPoint operator+(MyPoint& const other1, MyPoint& const other2);*/
	//friend istream& operator>>(istream &is, MyPoint &  P);
	//friend ostream& operator<<(ostream &os, MyPoint &  P);
	~MyPoint();
};

