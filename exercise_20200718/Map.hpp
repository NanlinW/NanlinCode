#pragma once

#include "RBTree.hpp"

#include <iostream>
using namespace std;


// map�д�ŵ���k-v�ļ�ֵ��pair<K, V>
namespace bite
{
	template<class K, class V>
	class map
	{
		typedef pair<K, V> ValueType;

		// KOFV���ã���value����ȡkey
		struct KeyOfValue
		{
			const K& operator()(const ValueType& value)
			{
				return value.first;
			}
		};

	public:
		typedef RBTree<ValueType, KeyOfValue> RBTree;

		/*
		typedef RBTree::iterator iterator;   // �����Ǳ���
		ԭ�򣺾�̬��Ա������ʽ--->����ͨ������::��̬��Ա����ֱ�ӽ��з���
		RBTree::iterator�����ڽ���ʱ�����ܻὫiterator������RBTree���о�̬�ĳ�Ա
		�����������iterator������RBTree�о�̬�ĳ�Աʱ�϶��������Ϊiterator��RBTree�е�һ������

		typename typedef RBTree::iterator iterator;  
		typename�����������typedef֮ǰ����ʾ��::����  ������������е����ͣ������Ǿ�̬��Ա
		�������ӣ���ȷ���߱�����iterator��RBTree�е�һ������
		*/
		typename typedef RBTree::iterator iterator;

	public:
		map()
			: t()
		{}

		iterator begin()
		{
			return t.begin();
		}

		iterator end()
		{
			return t.end();
		}


		//////////////////////////////////////////////////////////
		bool empty()const
		{
			return t.Empty();
		}

		size_t size()const
		{
			return t.Size();
		}

		//////////////////////////////////////////////////////////
		/*
		Ϊʲômap��[]Ҫ����insert��
		��Ϊoperator��ͨ��key����ȡ��key��Ӧ��value
		���key��Ӧ�ļ�ֵ����map�д���ʱ������ֱ�ӷ�����key��Ӧ��value�Ϳ�����
		���key��Ӧ�ļ�ֵ�Բ���map�д���ʱ��û�а취���з�����

		��ˣ�operator[]�ײ�ʹ��insert����ȡ��key��Ӧ��value
		insert��ԭ��
		<key, value>�ļ�ֵ���������в���ʱ��
		   ���key�ں�������Ѿ�����ʱ��insert����key��Ӧ�Ľڵ㹹��һ���������Լ�true������<�ҵ���key��Ӧ�Ľڵ㣬false>
		   ���key�ں�����в�����ʱ��insert����ɲ��룬������<�²���ڵ㹹���������true>

		   Ҫ��ȡ�����key��Ӧ��value��mapҲ��֪�������Ƿ������key��ȵļ�ֵ�ԣ�
		   map����<key, Ĭ�ϵ�value>����һ����ֵ�ԣ�������map�в��룬��������
		    1. ����ɹ���map�в�������key��ȵļ�ֵ�ԣ�����ֵ<�½ڵ��Ӧ�ĵ�������true>
			2. ����ʧ�ܣ�map���Ѿ�������key��ȵļ�ֵ�ԣ�����ֵ<��key�൱�Ľڵ��Ӧ�ĵ�����, false>

		*/
		V& operator[](const K& key)
		{
			return (*(insert(make_pair(key, V())).first)).second;
		}

		// value�������ǣ�pair<K, V>
		pair<iterator, bool> insert(const ValueType& value)
		{
			return t.Insert(value);
		}

		void clear()
		{
			t.Clear();
		}

		//////////////////////////////////////////////////////////////
		iterator find(const K& key)
		{
			return t.Find(make_pair(key, V()));
		}
	private:
		RBTree t;
	};
}


#include <string>

void TestMap()
{
	bite::map<string, string> m;
	m.insert(pair<string, string>("orange", "����"));
	m.insert(make_pair("apple", "ƻ��"));
	cout << m["apple"] << endl;
	cout << m["banana"] << endl;    //banana��Ӧ��key�����ڣ�map�Ƚ�<"banana", "">��ֵ���������в��룬Ȼ�󷵻�""

	m["banana"] = "�㽶";

	if (m.find("peach") == m.end())
	{
		m["peach"] = "����";
	}

	cout << m.size() << endl;

	auto it = m.begin();
	while (it != m.end())
	{
		cout << (*it).first << "--->" << it->second << endl;
		++it;
	}
	cout << endl;

	cout << "=============================" << endl;

	// ��Χfor
	for (auto& e : m)
		cout << e.first << "--->" << e.second << endl;
	cout << endl;

	m.clear();
	cout << m.size() << endl;
}