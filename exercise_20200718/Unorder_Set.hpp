#include "HashBucket.hpp"

namespace bite
{
	// unordered_set�����ǽ�key�洢���ײ�Ĺ�ϣͰ����
	template<class K, class HF = DefInt<K>>
	class unordered_set
	{
		typedef K ValueType;

		struct KOFV
		{
			const K& operator()(const ValueType& value)
			{
				return value;
			}
		};

		typedef HashBucket<ValueType, K, KOFV, HF> HT;
	public:

		// typename���ã���ȷ���߱�������HT::iterator��HT���е����ͣ������Ǿ�̬��Ա
		typename typedef HT::iterator iterator;


	public:
		unordered_set()
			: ht()
		{}

		///////////////////////////////////
		// ������
		iterator begin()
		{
			return ht.begin();
		}

		iterator end()
		{
			return ht.end();
		}

		//////////////////////////////////////////
		// ����
		bool empty()const
		{
			return ht.Empty();
		}

		size_t size()const
		{
			return ht.Size();
		}

		//////////////////////////////////////////////////
		// ����
		iterator find(const K& key)
		{
			return ht.Find(key);
		}

		////////////////////////////////////////////////
		// �޸�
		pair<iterator, bool> insert(const ValueType& data)
		{
			return ht.Insert(data);
		}

		size_t erase(const K& key)
		{
			return ht.Delete(key);
		}

		void clear()
		{
			ht.Clear();
		}

		void swap(unordered_map<K, HF>& m)
		{
			ht->Swap(m.ht);
		}

		////////////////////////////////////////
		// Ͱ��ز���
		// ��ȡͰ���ܸ���
		size_t bucket_count()const
		{
			return ht.BucketCount();
		}

		// ��ȡbucketNo�нڵ�ĸ���
		size_t bucket_size(size_t bucketNo)const
		{
			return ht.BucketSize(bucketNo);
		}

		// ��ȡkey���ڵ�Ͱ��
		size_t bucket(const K& key)
		{
			return ht.Bucket(key);
		}
	private:
		HT ht;
	};
}

#include <iostream>
using namespace std;

#include <string>
void TestUnorderSet()
{
	bite::unordered_set<string, Str2Int> m;
	m.insert("apple");
	m.insert("orange");
	m.insert("peach");
	m.insert("banana");
	m.insert("watermelon");

	cout << m.size() << endl;
	cout << m.bucket("orange") << endl;
	cout << m.bucket_size(m.bucket("orange")) << endl;

	/*
	auto it  = m.begin();
	while(it != m.end())
	{
	cout << "<" << it.first << ", " << it.second << "> ";
	++it;
	}
	cout<<endl;
	*/
	for (auto e : m)
		cout << e<<" ";
	cout << endl;


	auto it = m.find("orange");
	if (it != m.end())
	{
		cout << "orange is in" << endl;
	}

	m.erase("ornage");
	if (it != m.end())
	{
		cout << "orange is in" << endl;
	}
	else
	{
		cout << "û�иü�ֵ��" << endl;
	}

	m.clear();
	cout << m.size() << endl;
}