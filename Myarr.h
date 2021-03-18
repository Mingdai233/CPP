#ifndef _MYARR_H_
#define _MYARR_H_

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct student
{
	int age;
	char name[32];
	//运算符重载
	bool operator ==(const student &a)const
	{
		return (age == a.age && strcmp(name, a.name) == 0);
	}
}STU;

typedef STU SeqElemtype;

//动态数组
typedef struct SeqList
{
	SeqElemtype *head;
	int length;//元素个数
	int size;//数组大小
}SeqList;


namespace Myarr
{
	void CreateArr(SeqList &S,int size);
	bool ArrEmpty(SeqList S);
	void InserElement(SeqList &S, int pos, SeqElemtype e);
	void DeleteElement(SeqList &S, int pos);
	int ElementPos(SeqList S, SeqElemtype e);
	void ChangeElement(SeqList &S, int pos);
	void DestroyList(SeqList &S);
}





#endif // !_MYARR_H_
