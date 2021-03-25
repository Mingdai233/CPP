#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

class A
{
	int a;
public:
	A(int i);
	~A()
	{
		;
	}
};

class B:virtual public A
{
	int b;
public:
	B(int i);
	~B()
	{
		;
	}
};

class C:virtual public A
{
	int c;
public:
	C(int i);
	~C()
	{
		;
	}
};

class D :public B, public C
{
	int d;
public:
	D(int i);
	~D()
	{
		;
	}
};

C::C(int i) :A(2)
{
	c = i;
}

A::A(int i)
{
	a = i;
}


B::B(int i) :A(2)
{
	b = i;
}

D::D(int i):A(i),B(i), C(i)
{
	d=i;
}

int main()
{
	D dd(1);
	B bb(1);
	C cc(1);
	D* p = &dd;
	C* p1 = &cc;
	B* p2 = &bb;
	return 0;
}
