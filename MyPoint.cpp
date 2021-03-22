#include "MyPoint.h"


MyPoint::MyPoint()
{
	x = y = 0;
}


void MyPoint::SetPoint(int x, int y)
{
	this->x = x;
	this->y = y;
}

MyPoint MyPoint::operator+(int i)const
{
	MyPoint tempoint;
	tempoint.x = this->x + i;
	tempoint.y = this->y + i;
	return tempoint;
}

MyPoint MyPoint::operator+(MyPoint& const other)const
{
	MyPoint tempoint;
	tempoint.x = this->x + other.x;
	tempoint.y = this->y + other.y;
	return tempoint;
}
//
// istream& operator>>(istream &is, MyPoint &  P)
//{
//	 is >> P.x;
//	 is >> P.y;
//}
//
// ostream operator<<(ostream &os, MyPoint &  P)
// {
//	 os << P.x;
//	 os << P.y;
// }

//MyPoint operator+(MyPoint& const other1, MyPoint& const other2)
//{
//	MyPoint tempoint;
//	tempoint.x = other1.x + other2.x;
//	tempoint.y = other1.y + other2.y;
//	return tempoint;
//}

MyPoint::~MyPoint()
{
}
