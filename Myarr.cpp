#define _CRT_SECURE_NO_WARNINGS 1

#include"Myarr.h"

namespace Myarr
{
	//������̬����
	void CreateArr(SeqList &S, int size)//Ҫ�Լ�ת��ָ������
	{
		S.head = new SeqElemtype[size];
		if (!S.head)
		{
			perror("����ʧ��!");
			exit(EXIT_FAILURE);
		}
		S.size = size;
		S.length = 0;//Ԫ�ظ���Ϊ0
	}
	//�ж��Ƿ�Ϊ��
	bool ArrEmpty(SeqList S)
	{
		if (S.length == 0)
			return true;
		else
			return false;
	}
	//����Ԫ��
	void InserElement(SeqList &S, int pos, SeqElemtype e)
	{
		//�жϲ���λ���Ƿ���ȷ
		if (pos <= 0 || pos > S.length)
		{
			perror("����λ�ô���");
			return;
		}
		//�ж��Ƿ���Ҫ����
		if (S.length == S.size)
		{
			SeqElemtype* temp;
			temp = S.head;
			S.head = new SeqElemtype[S.size * 2];
			if (!S.head)
			{
				perror("�ڴ治�����ʧ��!");
				S.head = temp;
				return;
			}
			S.size *= 2;
			for (int i = 0; i < S.length; i++)
			{
				S.head[i] = temp[i];//ͬ���ͽṹ�����ֱ�Ӹ�ֵ
			}
			delete[]temp;
			temp = NULL;
		}
		//����
		for (int i = S.length - 1; i >= pos - 1; i--)
		{
			S.head[i + 1] = S.head[i];
		}
		S.head[pos - 1] = e;
		S.length++;
	}
	//ɾ��Ԫ��
	void DeleteElemnt(SeqList &S, int pos)
	{
		if (S.length == 0)
		{
			printf("��");
			return;
		}
		if (pos <= 0 || pos>S.length)
		{
			perror("λ����Ԫ�أ�");
			return;
		}
		//���Լ�����ݹ���
		//ɾ��
		for (int i = pos; i < S.length; i++)
		{
			S.head[i - 1] = S.head[i];
		}
		S.length--;
	}
	//����Ԫ���±�
	int ElementPos(SeqList S, SeqElemtype e)
	{
		for (int i = 0; i < S.length; i++)
		{
			if (S.head[i] == e)
			{
				return i;
			}
		}
		return -1;//û�ҵ�
	}
	//�޸�Ԫ�ص�ֵ(�滻)
	void ChangeElement(SeqList &S, int pos,SeqElemtype e)
	{
		if (pos <= 0 || pos>S.length)
		{
			perror("λ����Ԫ��!");
			return;
		}
		S.head[pos - 1] = e;
	}
	//��������
	void DestroyList(SeqList &S)
	{
		if (S.head)
			delete[] S.head;
	}
}

