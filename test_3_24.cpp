#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
using namespace std;

template<class K, class V>
struct AVLtreeNode
{
	typedef AVLtreeNode Node;
	K key;//关键值
	V data;//顶点数据
	Node *parent;
	Node *Lchild;
	Node *Rchild;
	int bf;//平衡因子
	AVLtreeNode(const K& key, const V& data)//AVL树节点初始化
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
	Node* root;//根节点
public:
	bool IsBalance()
	{
		return _IsBalance(root);
	}
	AVLtree() :root(NULL)
	{
		;
	}
	//插入一个节点
	bool Insert(const K& key, const V& data)
	{
		//树为空则作为根节点
		if (!root)
		{
			root = new Node(key, data);
			return true;
		}

		//不为空
		Node* cru = root;//当前节点
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
			else//key值相等不能录入
			{
				return false;
			}
		}
		//查看是插入parent节点的哪边
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
			if (parent->bf == 0)//原来bf为1或-1.插入后变0则树的高度没有改变
			{
				return true;//插入完成
			}
			else if (parent->bf == -1 || parent->bf == 1)//插入后高度发生变化
			{
				Node* pparent = parent->parent;
				//判断左边还是右边
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
			else//平衡因子不满足平衡树
			{
				if (parent->bf == 2)//左树过深
				{
					if (parent->Lchild->bf == 1)//LL结构
					{
						BlanceLL(parent);
						return true;
					}
					else if (parent->Lchild->bf == -1)//LR结构
					{
						BlanceLR(parent);
						return true;
					}
				}
				else//右树过深
				{
					if (parent->Rchild->bf == -1)//RR结构
					{
						BlanceRR(parent);
						return true;
					}
					else if (parent->Rchild->bf == 1)//RL结构
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
	//四种结构的操作
protected:
	void BlanceLL(Node *parent)
	{
		//判断传入的是否为空指针
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
		int bf = temproot->bf;//提前记录，旋转过后会改变
		BlanceRR(parent->Lchild);
		BlanceLL(parent);
		//修改bf值
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
		int bf = temproot->bf;//提前记录，旋转过后会改变
		BlanceLL(parent->Rchild);
		BlanceRR(parent);
		//修改bf值
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
			cout << root->key << "平衡因子异常" << endl;
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
		cout << "isbalance?" << tree.IsBalance() << "插入" << a[i] << endl;
	}
	tree.InorderTraverse();
	cout << endl;
	AVLtree<int, int> tree1;
	int a1[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	for (size_t i = 0; i < sizeof(a1) / sizeof(a1[0]); i++)
	{
		tree1.Insert(a1[i], i);
		cout << "isbalance?" << tree1.IsBalance() << "插入" << a1[i] << endl;
	}
	tree1.InorderTraverse();
}

