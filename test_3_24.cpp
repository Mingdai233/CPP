#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
using namespace std;

template<class K, class V>
struct AVLtreeNode
{
	typedef AVLtreeNode Node;
	K key;//�ؼ�ֵ
	V data;//��������
	Node *parent;
	Node *Lchild;
	Node *Rchild;
	int bf;//ƽ������
	AVLtreeNode(const K& key, const V& data)//AVL���ڵ��ʼ��
		:key(key)
		, data(data)
		, parent(NULL)
		, Lchild(NULL)
		, Rchild(NULL)
		, bf(0)
	{
		;
	}
};

template<class K, class V>
class AVLtree
{
	typedef AVLtreeNode<K, V> Node;
	Node* root;//���ڵ�
public:
	bool IsBalance()
	{
		return _IsBalance(root);
	}
	AVLtree() :root(NULL)
	{
		;
	}
	//����һ���ڵ�
	bool Insert(const K& key, const V& data)
	{
		//��Ϊ������Ϊ���ڵ�
		if (!root)
		{
			root = new Node(key, data);
			return true;
		}

		//��Ϊ��
		Node* cru = root;//��ǰ�ڵ�
		Node* parent = root;
		while (cru)
		{
			if (key < parent->key)
			{
				cru = parent->Lchild;
				if (cru)
					parent = parent->Lchild;
			}
			else if (key > parent->key)
			{
				cru = parent->Rchild;
				if (cru)
					parent = parent->Rchild;
			}
			else//keyֵ��Ȳ���¼��
			{
				return false;
			}
		}
		//�鿴�ǲ���parent�ڵ���ı�
		if (key < parent->key)
		{
			cru = new Node(key, data);
			cru->parent = parent;
			parent->Lchild = cru;
			parent->bf++;
		}
		else
		{
			cru = new Node(key, data);
			cru->parent = parent;
			parent->Rchild = cru;
			parent->bf--;
		}

		while (parent)
		{
			if (parent->bf == 0)//ԭ��bfΪ1��-1.������0�����ĸ߶�û�иı�
			{
				return true;//�������
			}
			else if (parent->bf == -1 || parent->bf == 1)//�����߶ȷ����仯
			{
				Node* pparent = parent->parent;
				//�ж���߻����ұ�
				if (pparent)
				{
					if (pparent->Lchild == parent)
					{
						pparent->bf++;
						parent = pparent;
					}
					else
					{
						pparent->bf--;
						parent = pparent;
					}
				}
				parent = pparent;
			}
			else//ƽ�����Ӳ�����ƽ����
			{
				if (parent->bf == 2)//��������
				{
					if (parent->Lchild->bf == 1)//LL�ṹ
					{
						BlanceLL(parent);
						return true;
					}
					else if (parent->Lchild->bf == -1)//LR�ṹ
					{
						BlanceLR(parent);
						return true;
					}
				}
				else//��������
				{
					if (parent->Rchild->bf == -1)//RR�ṹ
					{
						BlanceRR(parent);
						return true;
					}
					else if (parent->Rchild->bf == 1)//RL�ṹ
					{
						BlanceRL(parent);
						return true;
					}
				}
			}
		}
	}
	void InorderTraverse()
	{
		_InorderTraverse(root);
	}
	//���ֽṹ�Ĳ���
protected:
	void BlanceLL(Node *parent)
	{
		//�жϴ�����Ƿ�Ϊ��ָ��
		Node* temproot = parent->Lchild;
		parent->Lchild = temproot->Rchild;
		if (temproot->Rchild)
			temproot->Rchild->parent = parent;
		temproot->Rchild = parent;
		if (parent->parent)
		{
			temproot->parent = parent->parent;
			if (parent->parent->Lchild == parent)
			{
				parent->parent->Lchild = temproot;
			}
			else
			{
				parent->parent->Rchild = temproot;
			}
		}
		else
		{
			root = temproot;
			temproot->parent = NULL;
		}
		parent->parent = temproot;
		parent->bf = temproot->bf = 0;
	}
	void BlanceRR(Node *parent)
	{
		Node* temproot = parent->Rchild;
		parent->Rchild = temproot->Lchild;
		if (temproot->Lchild)
			temproot->Lchild->parent = parent;
		temproot->Lchild = parent;
		if (parent->parent)
		{
			temproot->parent = parent->parent;
			if (parent->parent->Lchild == parent)
			{
				parent->parent->Lchild = temproot;
			}
			else
			{
				parent->parent->Rchild = temproot;
			}
		}
		else
		{
			root = temproot;
			temproot->parent = NULL;
		}
		parent->parent = temproot;
		parent->bf = temproot->bf = 0;
	}
	void BlanceLR(Node *parent)
	{
		Node* temproot = parent->Lchild->Rchild;
		int bf = temproot->bf;//��ǰ��¼����ת�����ı�
		BlanceRR(parent->Lchild);
		BlanceLL(parent);
		//�޸�bfֵ
		if (bf == 1)
		{
			parent->bf = -1;
			temproot->Lchild->bf = 0;
		}
		else if (bf == -1)
		{
			parent->bf = 0;
			temproot->Lchild->bf = 1;
		}
		else
		{
			parent->bf = 0;
			temproot->Lchild->bf = 0;
		}
	}

	void BlanceRL(Node *parent)
	{
		Node* temproot = parent->Rchild->Lchild;
		int bf = temproot->bf;//��ǰ��¼����ת�����ı�
		BlanceLL(parent->Rchild);
		BlanceRR(parent);
		//�޸�bfֵ
		if (bf == 1)
		{
			parent->bf = 0;
			temproot->Rchild->bf = -1;
		}
		else if (bf == -1)
		{
			parent->bf = 1;
			temproot->Rchild->bf = 0;
		}
		else//bf==0
		{
			parent->bf = 0;
			temproot->Rchild->bf = 0;
		}
	}
	void _InorderTraverse(Node* root)
	{
		if (!root)
		{
			return;
		}
		_InorderTraverse(root->Lchild);
		cout << root->key << " ";
		_InorderTraverse(root->Rchild);
	}
	bool _IsBalance(Node* root)
	{
		if (NULL == root)
			return true;
		int bf = _Depth(root->Lchild) - _Depth(root->Rchild);
		if (bf == root->bf)
			return true;
		else
		{
			cout << root->key << "ƽ�������쳣" << endl;
			return false;
		}

		return _IsBalance(root->Lchild);
		return _IsBalance(root->Rchild);
	}

	int _Depth(Node* root)
	{
		if (NULL == root)
			return 0;
		int left = _Depth(root->Lchild) + 1;
		int right = _Depth(root->Rchild) + 1;
		return left > right ? left : right;
	}
};


int main()
{
	AVLtree<int, int> tree;
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		tree.Insert(a[i], i);
		cout << "isbalance?" << tree.IsBalance() << "����" << a[i] << endl;
	}
	tree.InorderTraverse();
	cout << endl;
	AVLtree<int, int> tree1;
	int a1[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	for (size_t i = 0; i < sizeof(a1) / sizeof(a1[0]); i++)
	{
		tree1.Insert(a1[i], i);
		cout << "isbalance?" << tree1.IsBalance() << "����" << a1[i] << endl;
	}
	tree1.InorderTraverse();
}

