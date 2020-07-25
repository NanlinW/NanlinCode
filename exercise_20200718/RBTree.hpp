#pragma once

#include <iostream>
using namespace std;


enum Color{RED, BLACK};


template<class T>
struct RBTreeNode
{
	RBTreeNode(const T& data = T(), Color color = RED)
	: _left(nullptr)
	, _right(nullptr)
	, _parent(nullptr)
	, _data(data)
	, _color(color)
	{}

	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	T _data;
	Color _color;
};


#if 0
// ���裺Ϊ�˼�����������ĺ�����е�ֵ��Ψһ��
template<class T>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	RBTree()
	{
		head = new Node;
		head->_left = head;
		head->_right = head;
		head->_parent = nullptr;
	}

	bool Insert(const T& data)
	{
		// root����ͷ�����parent�ı���
		Node*& root = GetRoot();

		// 1. ���ն����������Ĺ�������½ڵ�
		//if (NULL == head->_parent)
		if(NULL == root)  // ��Ϊroot��head��parent�ı��������޸�root��ָ������޸�head��parent��ָ��
		{
			root = new Node(data, BLACK);
			root->_parent = head;
			head->_left = root;
			head->_right = root;
			return true;
		}

		// ���ǿ�
		// ���ն����������Ĺ����Ҵ�����ڵ��ں������λ��
		Node* cur = root;
		Node* parent = NULL;
		while (cur)
		{
			parent = cur;
			if (data < cur->_data)
				cur = cur->_left;
			else if (data > cur->_data)
				cur = cur->_right;
			else
				return false;
		}

		// �����½ڵ�
		cur = new Node(data);
		if (data < parent->_data)
			parent->_left = cur;
		else
			parent->_right = cur;

		cur->_parent = parent;

		// 2. cur�ڵ�Ĭ�ϵ���ɫ�Ǻ�ɫ�����cur��˫��parent�ڵ����ɫ�Ǻ�ɫ��û��Υ���κκ����������
		//    ���cur��˫��parent�ڵ����ɫ�Ǻ�ɫ��Υ��������3��û������һ��ĺ�ɫ�ڵ�
		// ��Ҫ�Խڵ���ɫ���е��� + ��ת����
		while (parent != head && RED == parent->_color)  // ע�⣺ѭ�����������е�����
		{
			// Υ������������û������һ��ĺ�ɫ�ڵ�
			Node* grandFather = parent->_parent;
			if (parent == grandFather->_left)
			{
				Node* uncle = grandFather->_right;
				if (uncle && RED == uncle->_color)
				{
					// ����ڵ������Ϊ��---����һ
					parent->_color = BLACK;
					uncle->_color = BLACK;
					grandFather->_color = RED;
					cur = grandFather;
					parent = cur->_parent;
				}
				else
				{
					// ����ڵ㲻���� || ����ڵ���ڵ�����ɫ�Ǻ�ɫ
					if (cur == parent->_right)
					{
						// ������
						RotateLeft(parent);
						swap(parent, cur);
					}

					// ��������
					grandFather->_color = RED;
					parent->_color = BLACK;
					RotateRight(grandFather);
				}
			}
			else
			{
				Node* uncle = grandFather->_left;
				if (uncle && RED == uncle->_color)
				{
					parent->_color = BLACK;
					uncle->_color = BLACK;
					grandFather->_color = RED;
					cur = grandFather;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_left)
					{
						RotateRight(parent);
						swap(parent, cur);
					}

					grandFather->_color = RED;
					parent->_color = BLACK;
					RotateLeft(grandFather);
				}
			}
		}

		root->_color = BLACK;
		head->_left = LeftMost();
		head->_right = RightMost();
		return true;
	}

	void InOrder()
	{
		_InOrder(GetRoot());
		cout << endl;
	}

	Node* LeftMost()
	{
		Node* root = GetRoot();
		if (NULL == root)
			return head;

		Node* cur = root;
		while (cur->_left)
			cur = cur->_left;

		return cur;
	}

	Node* RightMost()
	{
		Node* root = GetRoot();
		if (NULL == root)
			return head;

		Node* cur = root;
		while (cur->_right)
			cur = cur->_right;

		return cur;
	}

	bool IsValidRBTree()
	{
		Node* root = GetRoot();
		if (nullptr == root)
			return true;

		if (BLACK != root->_color)
		{
			cout << "Υ�����ʶ������ڵ�����Ǻ�ɫ--->���ڵ㲻�Ǻ�ɫ��" << endl;
			return false;
		}

		// ��ȡһ��·���к�ɫ�ڵ�ĸ���: ��ȡ���������·���нڵ�ĸ���
		size_t blackCount = 0;
		Node* cur = root;
		while (cur)
		{
			if (BLACK == cur->_color)
				blackCount++;

			cur = cur->_left;
		}

		// ������·���к�ɫ�ڵ�ĸ����뵱ǰ·���к�ɫ�ڵ�����Ա�
		size_t pathCount = 0;
		return _IsValidRBTree(root, blackCount, pathCount);
	}


private:
	bool _IsValidRBTree(Node* root, const size_t blackCount, size_t pathCount)
	{
		if (nullptr == root)
			return true;

		if (BLACK == root->_color)
			pathCount++;

		Node* parent = root->_parent;
		// root��˫��ȷʵ�Ǵ���
		if (parent != head)
		{
			if (RED == root->_color && parent->_color == RED)
			{
				cout << "Υ��������3��û������һ��ĺ�ɫ�ڵ�--->������" << endl;
				return false;
			}
		}

		// root��һ��Ҷ�ӽڵ㣬˵���Ѿ��ҵ���һ��·��
		if (nullptr == root->_left && nullptr == root->_right)
		{
			if (pathCount != blackCount)
			{
				cout << "Υ��������4��ÿ��·���к�ɫ�ڵ�������--->���ڲ����" << endl;
				return false;
			}
		}

		return _IsValidRBTree(root->_left, blackCount, pathCount) &&
			   _IsValidRBTree(root->_right, blackCount, pathCount);
	}

	void _InOrder(Node* root)
	{
		if (root)
		{
			_InOrder(root->_left);
			cout << root->_data << " ";
			_InOrder(root->_right);
		}
	}

	Node*& GetRoot()
	{
		return head->_parent;
	}

	// parent����������
	void RotateLeft(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		subR->_left = parent;

		Node* pparent = parent->_parent;
		subR->_parent = pparent;
		parent->_parent = subR;

		if (pparent == head)
		{
			// ��ת֮ǰparent�Ǹ��ڵ�
			head->_parent = subR;
		}
		else
		{
			if (parent == pparent->_left)
				pparent->_left = subR;
			else
				pparent->_right = subR;
		}
	}

	void RotateRight(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		subL->_right = parent;

		Node* pparent = parent->_parent;
		subL->_parent = pparent;
		parent->_parent = subL;

		if (pparent == head)
		{
			head->_parent = subL;
		}
		else
		{
			if (parent == pparent->_left)
				pparent->_left = subL;
			else
				pparent->_right = subL;
		}
	}

private:
	Node* head;
};

void TestRBTree()
{
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	RBTree<int> bt;
	for (auto e : a)
		bt.Insert(e);

	bt.InOrder();
	cout << bt.LeftMost()->_data << endl;
	cout << bt.RightMost()->_data << endl;

	if (bt.IsValidRBTree())
	{
		cout << "bt is rbtree!!!" << endl;
	}
	else
	{
		cout << "bt is not rbtree!!!" << endl;
	}
}
#endif

/*
��ӵ������Ĳ��裺
1. ���������ײ����ݽṹ�����Է�һ������������
2. ���������и�������ȡ���� iterator
3. ������������begin��end�ķ���
*/


template<class T>
struct RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef RBTreeIterator<T> Self;

	RBTreeIterator(Node* node)
		: _node(node)
	{}

	// �õ���������ָ�����ƵĲ���
	T& operator*()
	{
		return _node->_data;
	}

	T* operator->()
	{
		//return &_node->_data;
		return &(operator*());
	}

	// �õ����������ƶ�
	Self& operator++()
	{
		Increment();  // ȡnode����һ���ڵ�
		return *this;
	}

	Self operator++(int)
	{
		Self temp(*this);
		Increment();  // ȡnode����һ���ڵ�
		return temp;
	}

	Self& operator--()
	{
		Decrement();  // ȡnode����һ���ڵ�
		return *this;
	}

	Self operator--(int)
	{
		Self temp(*this);
		Decrement();  // ȡnode����һ���ڵ�
		return temp;
	}

	// ���������ԱȽ�
	bool operator!=(const Self& s)
	{
		return _node != s._node;
	}

	bool operator==(const Self& s)
	{
		return _node == s._node;
	}

	// �õ�����ȡ��һ���ڵ�
	void Increment()
	{
		if (_node->_right)
		{
			// _node����һ���ڵ��Ϊ������������С�Ľڵ�--->�����Ľڵ�
			_node = _node->_right;
			while (_node->_left)
				_node = _node->_left;
		}
		else
		{
			// ���node�������������ڣ���node��Ľڵ����������˫����Ѱ��
			Node* parent = _node->_parent;
			while (_node == parent->_right)
			{
				_node = parent;
				parent = _node->_parent;
			}

			// ע�⣺�������ڸ��Ӵ����λ�� Ȼ����ڵ�û�������������ⳡ��
			if (_node->_right != parent)
				_node = parent;
		}
	}

	// �õ�����ȡǰһ���ڵ�
	void Decrement()
	{
		// ��_nodeС�Ľڵ㣬���ȵ�_node���������в���
		// Ӧ�õ��������������Ľڵ�--->���������������Ҳ�ڵ�
		if (_node == _node->_parent->_parent && _node->_color == RED)
		{
			// ��������end()��λ��
			_node = _node->_right;
		}
		else if (_node->_left)
		{
			_node = _node->_left;
			while (_node->_right)
				_node = _node->_right;
		}
		else
		{
			// _nodeû��������,��_node������
			Node* parent = _node->_parent;
			while (_node == parent->_left)
			{
				_node = parent;
				parent = _node->_parent;
			}

			_node = parent;
		}
	}

private:
	Node* _node;
};

// ���裺Ϊ�˼�����������ĺ�����е�ֵ��Ψһ��
// T: ��ʾ������д洢Ԫ�ص�����
// KOFV: ��ʾ��data����ȡkey�ķº�������
template<class T, class KOFV>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef RBTreeIterator<T> iterator;

public:
	RBTree()
		: _size(0)
	{
		head = new Node;
		head->_left = head;
		head->_right = head;
		head->_parent = nullptr;
	}

	~RBTree()
	{
		DestroyRBTree(head->_parent);
		delete head;
	}

	iterator begin()
	{
		return iterator(head->_left);
	}

	iterator end()
	{
		return iterator(head);
	}
	
	pair<iterator, bool> Insert(const T& data)
	{
		// root����ͷ�����parent�ı���
		Node*& root = GetRoot();

		// 1. ���ն����������Ĺ�������½ڵ�
		//if (NULL == head->_parent)
		if (NULL == root)  // ��Ϊroot��head��parent�ı��������޸�root��ָ������޸�head��parent��ָ��
		{
			root = new Node(data, BLACK);
			root->_parent = head;
			head->_left = root;
			head->_right = root;
			_size++;
			return make_pair(begin(), true);
		}

		// ���ǿ�
		// ���ն����������Ĺ����Ҵ�����ڵ��ں������λ��
		Node* cur = root;
		Node* parent = NULL;
		KOFV kofv;
		while (cur)
		{
			parent = cur;
			//if (kofv.operator()(data) < kofv.operator()(cur->_data))
			if (kofv(data) < kofv(cur->_data))
				cur = cur->_left;
			else if (kofv(data) > kofv(cur->_data))
				cur = cur->_right;
			else
				return make_pair(iterator(cur), false);
		}

		// �����½ڵ�
		cur = new Node(data);
		Node* newNode = cur;
		if (kofv(data) < kofv(parent->_data))
			parent->_left = cur;
		else
			parent->_right = cur;

		cur->_parent = parent;

		// 2. cur�ڵ�Ĭ�ϵ���ɫ�Ǻ�ɫ�����cur��˫��parent�ڵ����ɫ�Ǻ�ɫ��û��Υ���κκ����������
		//    ���cur��˫��parent�ڵ����ɫ�Ǻ�ɫ��Υ��������3��û������һ��ĺ�ɫ�ڵ�
		// ��Ҫ�Խڵ���ɫ���е��� + ��ת����
		while (parent != head && RED == parent->_color)  // ע�⣺ѭ�����������е�����
		{
			// Υ������������û������һ��ĺ�ɫ�ڵ�
			Node* grandFather = parent->_parent;
			if (parent == grandFather->_left)
			{
				Node* uncle = grandFather->_right;
				if (uncle && RED == uncle->_color)
				{
					// ����ڵ������Ϊ��---����һ
					parent->_color = BLACK;
					uncle->_color = BLACK;
					grandFather->_color = RED;
					cur = grandFather;
					parent = cur->_parent;
				}
				else
				{
					// ����ڵ㲻���� || ����ڵ���ڵ�����ɫ�Ǻ�ɫ
					if (cur == parent->_right)
					{
						// ������
						RotateLeft(parent);
						swap(parent, cur);
					}

					// ��������
					grandFather->_color = RED;
					parent->_color = BLACK;
					RotateRight(grandFather);
				}
			}
			else
			{
				Node* uncle = grandFather->_left;
				if (uncle && RED == uncle->_color)
				{
					parent->_color = BLACK;
					uncle->_color = BLACK;
					grandFather->_color = RED;
					cur = grandFather;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_left)
					{
						RotateRight(parent);
						swap(parent, cur);
					}

					grandFather->_color = RED;
					parent->_color = BLACK;
					RotateLeft(grandFather);
				}
			}
		}

		root->_color = BLACK;
		head->_left = LeftMost();
		head->_right = RightMost();
		_size++;
		return make_pair(iterator(newNode), true);
	}

	iterator Find(const T& data)
	{
		Node* cur = GetRoot();
		while (cur)
		{
			// KOFV��һ������  KOFV(): ����Ĭ�ϵ��޲ι��캯������һ����������(û�����ֵĶ���)
			// ��KOFV�������������()����������ȡdata�е�key
			if (KOFV()(data) == KOFV()(cur->_data))
				return iterator(cur);
			else if (KOFV()(data) < KOFV()(cur->_data))
				cur = cur->_left;
			else
				cur = cur->_right;
		}

		return end();
	}

	void InOrder()
	{
		_InOrder(GetRoot());
		cout << endl;
	}

	void Clear()
	{
		DestroyRBTree(GetRoot());
		_size = 0;
	}

	Node* LeftMost()
	{
		Node* root = GetRoot();
		if (NULL == root)
			return head;

		Node* cur = root;
		while (cur->_left)
			cur = cur->_left;

		return cur;
	}

	Node* RightMost()
	{
		Node* root = GetRoot();
		if (NULL == root)
			return head;

		Node* cur = root;
		while (cur->_right)
			cur = cur->_right;

		return cur;
	}

	bool IsValidRBTree()
	{
		Node* root = GetRoot();
		if (nullptr == root)
			return true;

		if (BLACK != root->_color)
		{
			cout << "Υ�����ʶ������ڵ�����Ǻ�ɫ--->���ڵ㲻�Ǻ�ɫ��" << endl;
			return false;
		}

		// ��ȡһ��·���к�ɫ�ڵ�ĸ���: ��ȡ���������·���нڵ�ĸ���
		size_t blackCount = 0;
		Node* cur = root;
		while (cur)
		{
			if (BLACK == cur->_color)
				blackCount++;

			cur = cur->_left;
		}

		// ������·���к�ɫ�ڵ�ĸ����뵱ǰ·���к�ɫ�ڵ�����Ա�
		size_t pathCount = 0;
		return _IsValidRBTree(root, blackCount, pathCount);
	}

	bool Empty()const
	{
		return nullptr == head->_parent;
	}

	size_t Size()const
	{
		return _size;
	}


private:
	void DestroyRBTree(Node*& root)
	{
		if (root)
		{
			DestroyRBTree(root->_left);
			DestroyRBTree(root->_right);
			delete root;
			root = nullptr;
		}
	}

	bool _IsValidRBTree(Node* root, const size_t blackCount, size_t pathCount)
	{
		if (nullptr == root)
			return true;

		if (BLACK == root->_color)
			pathCount++;

		Node* parent = root->_parent;
		// root��˫��ȷʵ�Ǵ���
		if (parent != head)
		{
			if (RED == root->_color && parent->_color == RED)
			{
				cout << "Υ��������3��û������һ��ĺ�ɫ�ڵ�--->������" << endl;
				return false;
			}
		}

		// root��һ��Ҷ�ӽڵ㣬˵���Ѿ��ҵ���һ��·��
		if (nullptr == root->_left && nullptr == root->_right)
		{
			if (pathCount != blackCount)
			{
				cout << "Υ��������4��ÿ��·���к�ɫ�ڵ�������--->���ڲ����" << endl;
				return false;
			}
		}

		return _IsValidRBTree(root->_left, blackCount, pathCount) &&
			_IsValidRBTree(root->_right, blackCount, pathCount);
	}

	void _InOrder(Node* root)
	{
		if (root)
		{
			_InOrder(root->_left);
			cout << root->_data << " ";
			_InOrder(root->_right);
		}
	}

	Node*& GetRoot()
	{
		return head->_parent;
	}

	// parent����������
	void RotateLeft(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		subR->_left = parent;

		Node* pparent = parent->_parent;
		subR->_parent = pparent;
		parent->_parent = subR;

		if (pparent == head)
		{
			// ��ת֮ǰparent�Ǹ��ڵ�
			head->_parent = subR;
		}
		else
		{
			if (parent == pparent->_left)
				pparent->_left = subR;
			else
				pparent->_right = subR;
		}
	}

	void RotateRight(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		subL->_right = parent;

		Node* pparent = parent->_parent;
		subL->_parent = pparent;
		parent->_parent = subL;

		if (pparent == head)
		{
			head->_parent = subL;
		}
		else
		{
			if (parent == pparent->_left)
				pparent->_left = subL;
			else
				pparent->_right = subL;
		}
	}

private:
	Node* head;
	size_t _size;  // ��ʾ������нڵ�ĸ���
};
