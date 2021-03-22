#define _CRT_SECURE_NO_WARNINGS 1

#include"MyPoint.h"


int main()
{
	MyPoint P;
	P.SetPoint(2, 3);
	P = P + 1;
	MyPoint C;
	C.SetPoint(3, 4);
	MyPoint D;
	D =C + P;
	return 0;
}