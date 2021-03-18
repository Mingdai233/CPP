#define _CRT_SECURE_NO_WARNINGS 1

#include"Myarr.h"

namespace Myarr
{
	//创建动态数组
	void CreateArr(SeqList &S, int size)//要自己转换指针类型
	{
		S.head = new SeqElemtype[size];
		if (!S.head)
		{
			perror("创建失败!");
			exit(EXIT_FAILURE);
		}
		S.size = size;
		S.length = 0;//元素个数为0
	}
	//判断是否为空
	bool ArrEmpty(SeqList S)
	{
		if (S.length == 0)
			return true;
		else
			return false;
	}
	//插入元素
	void InserElement(SeqList &S, int pos, SeqElemtype e)
	{
		//判断插入位置是否正确
		if (pos <= 0 || pos > S.length)
		{
			perror("插入位置错误！");
			return;
		}
		//判断是否需要扩容
		if (S.length == S.size)
		{
			SeqElemtype* temp;
			temp = S.head;
			S.head = new SeqElemtype[S.size * 2];
			if (!S.head)
			{
				perror("内存不足插入失败!");
				S.head = temp;
				return;
			}
			S.size *= 2;
			for (int i = 0; i < S.length; i++)
			{
				S.head[i] = temp[i];//同类型结构体可以直接赋值
			}
			delete[]temp;
			temp = NULL;
		}
		//插入
		for (int i = S.length - 1; i >= pos - 1; i--)
		{
			S.head[i + 1] = S.head[i];
		}
		S.head[pos - 1] = e;
		S.length++;
	}
	//删除元素
	void DeleteElemnt(SeqList &S, int pos)
	{
		if (S.length == 0)
		{
			printf("空");
			return;
		}
		if (pos <= 0 || pos>S.length)
		{
			perror("位置无元素！");
			return;
		}
		//可以加入减容功能
		//删除
		for (int i = pos; i < S.length; i++)
		{
			S.head[i - 1] = S.head[i];
		}
		S.length--;
	}
	//查找元素下标
	int ElementPos(SeqList S, SeqElemtype e)
	{
		for (int i = 0; i < S.length; i++)
		{
			if (S.head[i] == e)
			{
				return i;
			}
		}
		return -1;//没找到
	}
	//修改元素的值(替换)
	void ChangeElement(SeqList &S, int pos,SeqElemtype e)
	{
		if (pos <= 0 || pos>S.length)
		{
			perror("位置无元素!");
			return;
		}
		S.head[pos - 1] = e;
	}
	//销毁数组
	void DestroyList(SeqList &S)
	{
		if (S.head)
			delete[] S.head;
	}
}

