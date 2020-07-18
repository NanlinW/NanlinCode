#pragma once

#include <iostream>
using namespace std;


// ����˫�ױ�ʾ
template<class T>
struct AVLTreeNode
{
	AVLTreeNode<T>* _left;
	AVLTreeNode<T>* _right;
	AVLTreeNode<T>* _parent;
	T _data;
	int _bf;   // �ýڵ��ƽ������

	AVLTreeNode(const T& data = T())
		: _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _data(data)
		, _bf(0)
	{}
};


// ���裺AVL����ֵ����Ψһ��
template<class T>
class AVLTree
{
	typedef AVLTreeNode<T> Node;
public:
	AVLTree()
		: _root(nullptr)
	{}

	/*
	AVL���� ���������� + ÿ���ڵ��ƽ�����ӵľ���ֵ���ᳬ��1
	*/
	bool Insert(const T& data)
	{
		// ����һ�ö���������
		if (nullptr == _root)
		{
			_root = new Node(data);
			return true;
		}

		// ���ն��������������ʽ�data�Ľڵ����
		// ���ն����������������Ҵ�����ڵ������е�λ��
		Node* cur = _root;
		Node* pParent = nullptr;
		while (cur)
		{
			pParent = cur;
			if (data < cur->_data)
				cur = cur->_left;
			else if (data > cur->_data)
				cur = cur->_right;
			else
				return false;
		}

		// �����½ڵ�
		cur = new Node(data);
		if (data < pParent->_data)
			pParent->_left = cur;
		else
			pParent->_right = cur;

		cur->_parent = pParent;

		// �������½ڵ����֮��Ϳ��Խ�����
		// AVL����Ϊ�½ڵ�������ܻ��ƻ�����ƽ����
		// ����parent�ڵ��ƽ������
		while (pParent)
		{
			if (cur == pParent->_left)
				pParent->_bf--;
			else
				pParent->_bf++;

			// ���parent��ƽ�������Ƿ�Υ��AVL��������
			if (0 == pParent->_bf)
				return true;
			else if (1 == pParent->_bf || -1 == pParent->_bf)
			{
				// ˵�����ڲ���֮ǰparentһ����Ҷ�ӽڵ�
				// parent��ƽ�����Ӹ������֮�������1˵����parent�������ĸ߶�������һ��
				// parent��ƽ�����Ӹ������֮�������-1˵����parent�������ĸ߶�������һ��
				// ��parentΪ���Ķ����������ĵ��׾�������1�㣬��Ҫ�������ϸ���
				cur = pParent;
				pParent = cur->_parent;
			}
			else
			{
				// parent��ƽ�����ӣ�2����-2---->parent�ڵ�Υ����AVL��������
				// ��ת����
				// parent��ƽ�����������2--->�����Ҫ���еĿ϶�������
				// ���parent��cur��ͬ��--->����
				// ���parent��cur�����--->����˫��
				if (2 == pParent->_bf)
				{
					// ˫�׵��������Ƚϸ�--->���һ�ο϶�������
					if (1 == cur->_bf)
						RotateLeft(pParent);
					else
						RotateRL(pParent);
				}
				else
				{
					// ˫�׵��������Ƚϸ�--->���һ�ο϶���Ҫ�ҵ���
					if (-1 == cur->_bf)
						RotateRight(pParent);
					else
						RotateLR(pParent);
				}

				// ��ת���֮����parentΪ���Ķ������߶�������½ڵ�֮ǰ�ĸ߶���ͬ
				// ��ת���֮��Ͳ����parent���ϲ����Ӱ��
				break;
			}
		}

		return true;
	}

	void InOrder()
	{
		_InOrder(_root);
	}

private:

	void _InOrder(Node* root)
	{
		if (root)
		{
			_InOrder(root->_left);
			cout << root->_data << " ";
			_InOrder(root->_right);
		}
	}

	void RotateLeft(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		// �ҵ�֧��subRLΪ��
		if (subRL)
			subRL->_parent = parent;

		subR->_left = parent;
		Node* PParent = parent->_parent;

		// ����parent��subR��˫��
		parent->_parent = subR;
		subR->_parent = PParent;

		// ѭ��֮ǰ��parent�Ǹ��ڵ�
		if (NULL == PParent)
		{
			_root = subR;
			subR->_parent = NULL;
		}
		else
		{
			// ѭ��֮ǰ��parent��˫��
			if (PParent->_left == parent)
				PParent->_left = subR;
			else
				PParent->_right = subR;
		}

		parent->_bf = subR->_bf = 0;
	}

	void RotateRight(Node* pParent)
	{
		// pSubL: pParent������
		// pSubLR: pParent���ӵ��Һ��ӣ�ע�⣺��
		Node* pSubL = pParent->_left;
		Node* pSubLR = pSubL->_right;
		// ��ת���֮��30���Һ�����Ϊ˫�׵�����
		pParent->_left = pSubLR;
		// ���30�����ӵ��Һ��Ӵ��ڣ�������˫��
		if (pSubLR)
			pSubLR->_parent = pParent;
		// 60 ��Ϊ 30���Һ���
		pSubL->_right = pParent;

		// ��Ϊ60�����ǿ�����������ڸ�����˫��ǰ�����ȱ���60��˫��
		Node* pPParent = pParent->_parent;
		// ����60��˫��
		pParent->_parent = pSubL;
		// ����30��˫��
		pSubL->_parent = pPParent;
		// ���60�Ǹ��ڵ㣬����ָ����ڵ��ָ��
		if (NULL == pPParent)
		{
			_root = pSubL;
			pSubL->_parent = NULL;
		}
		else
		{
			// ���60����������������˫�׵���������Ҳ������������
			if (pPParent->_left == pParent)
				pPParent->_left = pSubL;
			else
				pPParent->_right = pSubL;
		}
		// ���ݵ�����Ľṹ���²��ֽڵ��ƽ������
		pParent->_bf = pSubL->_bf = 0;
	}

	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		// ��ת֮ǰ����Ҫ����subRL��ƽ������
		// ��Ϊ��ת���֮����Ҫ����subRL֮ǰ��ƽ�����ӵ�����ת֮�󲿷ֽڵ��ƽ������
		int bf = subRL->_bf;
		RotateRight(parent->_right);
		RotateLeft(parent);

		if (1 == bf)
			parent->_bf = -1;
		else if (-1 == bf)
			subR->_bf = 1;
	}

	// ��ת֮ǰ��60��ƽ�����ӿ�����-1/0/1����ת���֮�󣬸�������������ڵ��ƽ�����ӽ��е���
	void RotateLR(Node* pParent)
	{
		Node* pSubL = pParent->_left;
		Node* pSubLR = pSubL->_right;
		// ��ת֮ǰ������pSubLR��ƽ�����ӣ���ת���֮����Ҫ���ݸ�ƽ�����������������ڵ��ƽ������
		
		int bf = pSubLR->_bf;
		// �ȶ�30��������
		RotateLeft(pParent->_left);
		// �ٶ�90�����ҵ���
		RotateRight(pParent);

		if (1 == bf)
			pSubL->_bf = -1;
		else if (-1 == bf)
			pParent->_bf = 1;
	}

private:
	Node* _root;
};


void TestAVLTree()
{
	int array[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };

	AVLTree<int> t;
	for (auto e : array)
		t.Insert(e);

	t.InOrder();
}