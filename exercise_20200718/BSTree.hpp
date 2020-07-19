#pragma once


#include <iostream>
using namespace std;

template<class K, class V>
struct BSTNode
{
	BSTNode<K, V>* _left;
	BSTNode<K, V>* _right;
	K _key;
	V _value;

	BSTNode(const K& key = K(), const V& value = V())
		: _left(nullptr)
		, _right(nullptr)
		, _key(key)
		, _value(value)
	{}
};


/*
1. ����ϿΣ������ܽ�
2. ���Σ�ǰ��Ƿ�Ŀγ̣�����ѧ�Ĳ���ʵ��ʱȥ��
3. ѧ��֪ʶ�㼰ʱ�����ܽ᣺֪ʶ�� + ���ô���
4. ���ˢ�⣺ÿ��һ�� + ��ָoffer
*/
template<class K, class V>
class BSTree
{
	typedef BSTNode<K, V> Node;
public:
	BSTree()
		: _root(nullptr)
	{}

	~BSTree()
	{
		_Destroy(_root);
	}

	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (key == cur->_key)
				return cur;
			else if (key < cur->_key)
				cur = cur->_left;
			else
				cur = cur->_right;
		}

		return nullptr;
	}

	bool Insert(const K& key, const V& value)
	{
		// ����---ֱ�Ӳ���
		if (nullptr == _root)
		{
			_root = new Node(key, value);
			return true;
		}

		// �ǿգ�
		// 1. �Ҵ�����ڵ��ڶ����������е�λ�ã� �ҵĹ����б���cur��˫��
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (key < cur->_key)
				cur = cur->_left;
			else if (key > cur->_key)
				cur = cur->_right;
			else
				return false;
		}


		// ����ڵ�
		cur = new Node(key, value);
		if (key < parent->_key)
			parent->_left = cur;
		else
			parent->_right = cur;

		return true;
	}

	bool Erase(const K& key)
	{
		// ����----ֱ�ӷ���
		/*if (nullptr == _root)
			return false;*/

		// ���ǿ�
		// ���ڶ������������ҵ�ֵΪkey�Ľڵ�
		// ����Ҫ����cur��˫��
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (key == cur->_key)
				break;
			else if (key < cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				parent = cur;
				cur = cur->_right;
			}
		}

		// �����������в�����key�Ľڵ�
		if (cur == nullptr)
			return false;

		// cur���գ�˵������ȫ���������Ѿ��ҵ�key�Ľڵ�
		// ���ýڵ�Ӷ�����������ɾ��
		if (nullptr == cur->_right)   // curһ��û���Һ���
		{
			// cur������������ || û������---->ֱ��ɾ��
			if (nullptr == parent)
			{
				// cur�ڵ��Ǹ��ڵ�
				_root = cur->_left;
			}
			else
			{
				// cur��˫��һ������
				if (cur == parent->_left)
					parent->_left = cur->_left;
				else
					parent->_right = cur->_left;
			}
		}
		else if (nullptr == cur->_left)  // curһ�����Һ���
		{
			// curֻ���Һ���--->ֱ��ɾ��
			if (nullptr == parent)
				_root = cur->_right;
			else
			{
				if (cur == parent->_left)
					parent->_left = cur->_right;
				else
					parent->_right = cur->_right;
			}
		}
		else
		{
			// cur�ڵ����Һ��Ӿ�����---����ֱ��ɾ��
			// 1. ��cur����������һ������ڵ�
			// cur���������ң������������������Ľڵ㣬�����������Ҳ�ڵ�
			// cur���������ң�����������������С�Ľڵ㣬�������������ڵ�

			parent = cur;
			Node* pDelNode = cur->_right;
			while (pDelNode->_left)
			{
				parent = pDelNode;
				pDelNode = pDelNode->_left;
			}
				
			cur->_key = pDelNode->_key;

			// ɾ������ڵ�
			if (pDelNode == parent->_left)
				parent->_left = pDelNode->_right;
			else
				parent->_right = pDelNode->_right;

			cur = pDelNode;
		}
		
		delete cur;
		return true;
	}

	void InOrder()
	{
		_InOrder(_root);
	}

	Node* LeftMost()
	{
		if (NULL == _root)
			return nullptr;

		Node* cur = _root;
		while (cur->_left)
			cur = cur->_left;

		return cur;
	}

	Node* RightMost()
	{
		if (NULL == _root)
			return nullptr;

		Node* cur = _root;
		while (cur->_right)
			cur = cur->_right;

		return cur;
	}

	void Clear()
	{
		_Destroy(_root);
	}

private:
	void _Destroy(Node*& root)
	{
		if (root)
		{
			_Destroy(root->_left);
			_Destroy(root->_right);
			delete root;
			root = nullptr;
		}
	}

	void _InOrder(Node* root)
	{
		if (root)
		{
			_InOrder(root->_left);
			cout << root->_key << " ";
			_InOrder(root->_right);
		}
	}

private:
	Node* _root;
};


void TestBSTree()
{
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	BSTree<int, int> bt;
	for (auto e : a)
		bt.Insert(e, e);

	bt.InOrder();
	cout << bt.LeftMost()->_key << endl;
	cout << bt.RightMost()->_key << endl;


	bt.Erase(8);
	bt.InOrder();

	bt.Erase(0);
	bt.InOrder();

	bt.Erase(1);
	bt.InOrder();

	bt.Erase(5);
	bt.InOrder();
}