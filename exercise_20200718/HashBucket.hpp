#pragma once

#include <iostream>
using namespace std;

#include <vector>
#include <string>

#include "Common.h"


template<class T>
struct HashNode
{
	HashNode<T>* _next;
	T _data;

	HashNode(const T& data = T())
		: _next(nullptr)
		, _data(data)
	{}
};


// ���ַ���ת��Ϊ���ε����ݣ�
struct Str2Int
{
	size_t operator()(const string& s)
	{
		const char* str = s.c_str();
		unsigned int seed = 131; // 31 131 1313 13131 131313
		unsigned int hash = 0;
		while (*str)
		{
			hash = hash * seed + (*str++);
		}
		return (hash & 0x7FFFFFFF);
	}
};

template<class T>
struct DefInt
{
	size_t operator()(const T& data)
	{
		return data;
	}
};


template<class T, class K, class KOFV, class DF = DefInt<T>>
class HashBucket;

template<class T, class K, class KOFV, class HF = DefInt<T>>
class HashBucketIterator
{
	typedef HashNode<T> Node;
	typedef HashBucketIterator<T, K, KOFV, HF> Self;
public:
	HashBucketIterator(HashBucket<T, K, KOFV, HF>* ht, Node* node)
		: _node(node)
		, _ht(ht)
	{}

	// ����ָ�����ƵĲ���
	T& operator*()
	{
		return _node->_data;
	}

	T* operator->()
	{
		// return &_node->_data;
		return &(operator*());
	}

	// �����������ƶ���һ��Ͱ�����꣬Ȼ��ȡ��һ��Ͱ
	Self& operator++()  // ǰ��++
	{
		Next();
		return *this;
	}

	Self operator++(int)  // ����++
	{
		Self temp(*this);
		Next();
		return temp;
	}

	// ע�⣺HashBucket�ĵ�������֧��--�Ĳ�������Ϊ��ײ�ʹ�õ��ǵ�������������--��ǰ�ƶ�

	// �ܹ��Ƚ�
	bool operator==(const Self& s)
	{
		return _ht == s._ht && _node == s._node;
	}

	bool operator!=(const Self& s)
	{
		return !(*this == s);
	}
private:
	void Next()
	{
		if (_node->_next)
		{
			_node = _node->_next;
		}
		else
		{
			// _node�ǵ�ǰ�����е����һ���ڵ�
			// ��ʱ����������ƶ�ʱ��_nodeӦ�ý��������һ���ǿ�Ͱ��������׽ڵ��λ��

			// ��_node���ڵ�ǰͰ��ʼ����һ���ǿ�Ͱ
			size_t bucketNo = _ht->HashFunc(KOFV()(_node->_data)) + 1;

			for (; bucketNo < _ht->BucketCount(); ++bucketNo)
			{
				if (_ht->_table[bucketNo])
				{
					// _table�ǹ�ϣͰ�����е�˽�г�Ա���ó�����ֱ�ӷ���
					_node = _ht->_table[bucketNo];
					return;
				}
			}

			_node = nullptr;
		}
	}
private:
	Node* _node;
	HashBucket<T, K, KOFV, HF>* _ht;   // ����һ����ϣͰ�Ķ���
};

// ���������ϣͰ�е�Ԫ��Ψһ
// T: ��ʾ��ϣͰ�д洢Ԫ�ص����ͣ������Ǽ�ֵ�ԣ�Ҳ������key
// K�� ��ʾ��ϣͰ�д洢Ԫ�ص�key������
// KOFV: ��value�н�key��ȡ����������
// DF: ��keyת��Ϊ���ε�����
template<class T,class K, class KOFV, class DF>
class HashBucket
{
	// Ϊ����HashBucketIterator����HashBucket�е�˽�г�Ա--->������Ԫ
	friend class HashBucketIterator<T, K, KOFV, DF>;

	typedef HashNode<T> Node;
	typedef HashBucket<T, K, KOFV, DF> Self;

public:
	typedef HashBucketIterator<T, K, KOFV, DF> iterator;

public:
	HashBucket(size_t initCap = 10)
		: _table(GetNextPrime(initCap))
		, _size(0)
	{}

	~HashBucket()
	{
		Clear();
	}

	iterator begin()
	{
		// ��һ���ǿ�Ͱ�еĵ�һ���ڵ��λ��
		for (size_t bucketNo = 0; bucketNo < BucketCount(); ++bucketNo)
		{
			if (_table[bucketNo])
			{
				return iterator(this, _table[bucketNo]);
			}
		}

		return end();
	}

	iterator end()
	{
		return iterator(this, nullptr);
	}

	pair<iterator, bool> Insert(const T& data)
	{
		CheckCapacity();

		// 1. ��ͨ����ϣ��������Ͱ��
		size_t bucketNo = HashFunc(KOFV()(data));

		// 2. �ҵ�Ͱ--->�ҵ�Ҫ���ĸ������в���
		Node* cur = _table[bucketNo];

		// 3. ����Ԫ���Ƿ��ڹ�ϣͰ��---����bucketͰ����Ԫ���Ƿ����--->�ڶ�Ӧ���������Ƿ����ֵΪdata�Ľڵ�
		while (cur)
		{
			// Ԫ����������򲻲���
			if (KOFV()(cur->_data) == KOFV()(data))
				return make_pair(iterator(this, cur), false);

			cur = cur->_next;
		}

		// 4. �����½ڵ�
		cur = new Node(data);

		// ʹ��ͷ��
		cur->_next = _table[bucketNo];
		_table[bucketNo] = cur;
		++_size;
		return make_pair(iterator(this, cur), true);
	}

	size_t Delete(const K& key)
	{
		// 1. ��ͨ����ϣ��������Ͱ��
		size_t bucketNo = HashFunc(key);

		// 2. �ҵ�Ͱ--->�ҵ�Ҫ���ĸ�������ɾ���ڵ�
		Node* cur = _table[bucketNo];
		Node* prev = nullptr;
		// 3. ����Ԫ���Ƿ��ڹ�ϣͰ��---����bucketͰ����Ԫ���Ƿ����--->�ڶ�Ӧ���������Ƿ����ֵΪdata�Ľڵ�
		while (cur)
		{
			// Ԫ�����������ɾ��
			if(KOFV()(cur->_data) == key)
			{
				// ͷɾ
				if (prev == nullptr)
				{
					_table[bucketNo] = cur->_next;
				}
				else
				{
					// ����λ��ɾ��
					prev->_next = cur->_next;
				}

				delete cur;
				--_size;
				return 1;
			}

			prev = cur;
			cur = cur->_next;
		}


		// ��ϣ���в�����ֵΪdata�Ľڵ�
		return 0;
	}

	iterator Find(const K& key)
	{
		// 1. ��ͨ����ϣ��������Ͱ��
		size_t bucketNo = HashFunc(key);

		// 2. �ҵ�Ͱ--->�ҵ�Ҫ���ĸ������в���
		Node* cur = _table[bucketNo];

		while (cur)
		{
			if (KOFV()(cur->_data) == key)
				return iterator(this, cur);

			cur = cur->_next;
		}

		return end();
	}

	size_t Size()const
	{
		return _size;
	}

	bool Empty()const
	{
		return 0 == _size;
	}

	void Clear()
	{
		// ����ÿ��Ͱ������нڵ���ɾ��
		// �������ɾ��ÿ�������е�����Ԫ��
		for (size_t bucketNo = 0; bucketNo < _table.capacity(); ++bucketNo)
		{
			Node* cur = _table[bucketNo];
			while (cur)
			{
				// ͷɾ
				_table[bucketNo] = cur->_next;
				delete cur;
				cur = _table[bucketNo];
			}
		}

		_size = 0;
	}

	size_t BucketCount()const
	{
		return _table.capacity();
	}

	// ����bucketNo�нڵ������
	size_t BucketSize(size_t bucketNo)const
	{
		Node* cur = _table[bucketNo];
		size_t count = 0;
		while (cur)
		{
			count++;
			cur = cur->_next;
		}

		return count;
	}

	size_t Bucket(const K& key)const
	{
		return HashFunc(key);
	}

	///////////////////////////////////////////////////////
	// ����ʹ�ø�����ӡ
	void PrintHashBucket()
	{
		for (size_t bucketNo = 0; bucketNo < _table.capacity(); ++bucketNo)
		{
			cout << "table[" << bucketNo << "]:";
			Node* cur = _table[bucketNo];
			while (cur)
			{
				cout << cur->_data << "--->";
				cur = cur->_next;
			}

			cout << "NULL" << endl;
		}
		cout << endl;
	}

	void Swap(Self& ht)
	{
		_table.swap(ht._table);
		swap(_size, ht._size);
	}

private:
	size_t HashFunc(const K& key)const
	{
		// DF()(data): ͨ��DF�������������󣬵�����operator()�����ؽ�dataת��Ϊ����
		return DF()(key) % _table.capacity();
	}

	/*
	// ˼�����������ݷ�ʽ���õĵط������
	void CheckCapacity()
	{
		// ����ϣ������ЧԪ�ظ�����Ͱ�ĸ������ʱ��������
		if (_size == _table.capacity())
		{
			// �����µĹ�ϣ��
			HashBucket<T> newHt(_size*2);

			// ���ɹ�ϣ��(this)�е�Ԫ�ز��뵽�¹�ϣ����
			for (size_t i = 0; i < _table.capacity(); ++i)
			{
				Node* cur = _table[i];
				while (cur)
				{
					newHt.Insert(cur->_data);
					cur = cur->_next;
				}
			}

			// ��������ϣ����Ԫ�ؽ���--->����֮��
			// this�д洢newHt�еĽڵ㣬newHt�д洢�ľ��Ǿ�this�нڵ�
			// ���˺�����������newHtҪ�����٣�newHtͰ�еĽڵ�ͻᱻ�ͷ�-->����ԭthis�еĽڵ�������
			this->Swap(newHt);
		}
	}
	*/

	void CheckCapacity()
	{
		// ����ϣ������ЧԪ�ظ�����Ͱ�ĸ������ʱ��������
		if (_size == _table.capacity())
		{
			// �����µĹ�ϣ��
			Self newHt(GetNextPrime(_size));

			// ���ɹ�ϣ��(this)�е�Ԫ�ز��뵽�¹�ϣ����
			for (size_t i = 0; i < _table.capacity(); ++i)
			{
				Node* cur = _table[i];
				while (cur)
				{
					// ��cur�ڵ�Ӿɹ�ϣͰ��ɾ��--ͷɾ
					_table[i] = cur->_next;

					// ��cur�ڵ����µĹ�ϣͰ�в���
					// ����Ԫ�����¹�ϣ���е�Ͱ��
					size_t bucketNo = newHt.HashFunc(KOFV()(cur->_data));

					// ͷ��
					cur->_next = newHt._table[bucketNo];
					newHt._table[bucketNo] = cur;
					
					cur = _table[i];
				}
			}

			// ��������ϣ����Ԫ�ؽ���--->����֮��
			// �ɹ�ϣͰ�����еĽڵ��Ѿ����Ƶ��¹�ϣͰ���ˣ��ɹ�ϣͰ����Ϊ��
			// this�д洢newHt�еĽڵ㣬newHt�д洢�ľ��Ǿ�this�нڵ�
			// ���˺�����������newHtҪ�����٣�newHtͰ�еĽڵ�ͻᱻ�ͷ�-->����ԭthis�еĽڵ�������
			this->Swap(newHt);
		}
	}
private:
	vector<Node*> _table;
	size_t _size;  // ��ʾ��ϣ������ЧԪ�صĸ���
};

/*
void TestHashBucket1()
{
	HashBucket<int> ht(10);

	int array[] = {1,4,5,6,7,9,11,14,15,16};
	for (auto e : array)
		ht.Insert(e);
	ht.PrintHashBucket();

	ht.Insert(17);
	ht.PrintHashBucket();

	auto it = ht.begin();
	while (it != ht.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	cout << ht.Size() << endl;
	ht.PrintHashBucket();

	ht.Insert(54);
	ht.Insert(44);
	ht.PrintHashBucket();

	if (ht.end() == ht.Find(44))
	{
		cout << "44 is not in hashbucket!!!" << endl;
	}
	else
	{
		cout << "44 is  in hashbucket!!!" << endl;
	}

	ht.Delete(44);
	if (ht.end() == ht.Find(44))
	{
		cout << "44 is not in hashbucket!!!" << endl;
	}
	else
	{
		cout << "44 is  in hashbucket!!!" << endl;
	}

	ht.Delete(54);
	ht.PrintHashBucket();

	ht.Clear();
	cout << ht.Size() << endl;
}


void TestHashBucket2()
{
	HashBucket<string, Str2Int> ht(10);
	ht.Insert("hello");
	ht.Insert("world");
}
*/

