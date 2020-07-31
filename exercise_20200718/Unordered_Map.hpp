#include "HashBucket.hpp"


namespace bite
{
	// unordered_map�����ǽ���ֵ�Դ洢���ײ�Ĺ�ϣͰ����
	template<class K, class V, class HF = DefInt<K>>
	class unordered_map
	{
		typedef pair<K, V> ValueType;

		struct KOFV
		{
			const K& operator()(const ValueType& value)
			{
				return value.first;
			}
		};

		typedef HashBucket<ValueType, K, KOFV, HF> HT;
	public:

		// typename���ã���ȷ���߱�������HT::iterator��HT���е����ͣ������Ǿ�̬��Ա
		typename typedef HT::iterator iterator;
	public:
		unordered_map()
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

		V& operator[](const K& key)
		{
			//return (*(ht.Insert(make_pair(key, V()).first))).second;
			return (*((this->insert(make_pair(key, V()))).first)).second;
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

		void swap(unordered_map<K, V, HF>& m)
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
void TestUnorderMap()
{
	bite::unordered_map<int, string> m;
	m.insert(make_pair(1, "apple"));
	m.insert(make_pair(2, "orange"));
	m.insert(make_pair(3, "peach"));
	m.insert(make_pair(4, "banana"));
	m.insert(make_pair(5, "watermelon"));

	cout << m.size() << endl;
	cout << m.bucket(2) << endl;
	cout << m.bucket_size(m.bucket(2)) << endl;

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
		cout << "<" << e.first << ", " << e.second << "> ";
	cout << endl;

	
	cout << m[1] << endl;
	auto it = m.find(1);
	if (it != m.end())
	{
		cout << it->second << endl;
	}

	m.erase(1);
	if (it != m.end())
	{
		cout << it->second << endl;
	}
	else
	{
		cout << "û�иü�ֵ��" << endl;
	}

	m.clear();
	cout << m.size() << endl;
}