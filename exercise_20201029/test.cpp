#include <iostream>
using namespace std;


#if 0

int main()
{
	int* p = (int*)malloc(sizeof(int) * 10);

	realloc(p, 100);
	return 0;
}
#endif


#if 0
#include <iostream>
using namespace std;
int main()
{
	void* p = new char[0xfffffffful];
	cout << "new:" << p << endl;
	return 0;
}
#endif

#if 0
//ע�⣺����ģ�岢���������ĺ���
// �����û����߸����������ɴ���Ĺ���
template<class T>
T Add(T left, T right)
{
	cout << typeid(T).name() << endl;
	return left + right;
}


/*
����ģ��ԭ��
1. ��ʽʵ������û����ȷָ��ģ������б�T��ʵ������
   �ڱ������׶Σ���������Ҫ�Դ��ݵ�ʵ�����ͽ������ݣ�����
   ���ݵĽ����ȷ��ģ������б���T��ʵ�����ͣ�
   ���T�����Ϳ���ȷ���������ɴ���������͵ĺ���
   ���T�������޷�ȷ���򱨴�

2. ��ʽʵ��������ȷָ����ģ������б���T��ʵ������
	�������ͻ�ֱ�Ӹ����û����ṩ��T������������
	����������͵ĺ���
	����������֮�������������ƥ�䣬�����
	����������Ͳ�ƥ�䣬��������ʽ����ת��
	���ת���ɹ��������ͨ��
	���ת��ʧ�ܣ��򱨴�
*/
int main()
{
	// ��ʽʵ����
	Add(1, 2);   // Add<int>
	Add(1.0, 2.0); // Add<double>
	Add('1', '2'); // Add<char>
	Add(1, (int)2.0); //Add<int> // 1-->int  2.0-->double

	// ��ʽʵ����
	Add<int>(1, 2.0);
	// Add<int>(1, "123"); ����ʧ��
	return 0;
}
#endif


#if 0
template<class T1, typename T2>
T2 Add(T1 left, T2 right)
{
	return left + right;
}

int main()
{
	Add(1, 2.0);
	Add(1, 2);
	return 0;
}
#endif

#if 0
template<class T>
T Add(T left, T right)
{
	return left + right;
}

int Add(int left, int right)
{
	return left + right;
}

int main()
{
	Add(1, 2);

	Add<int>(1, 2);
	Add<>(1, 2);  //��ʽʵ����
	return 0;
}
#endif


int Add(int left, int right)
{
	return left + right;
}


template<class T1, typename T2>
T2 Add(T1 left, T2 right)
{
	return left + right;
}

int main()
{
	Add(1, 2);
	Add(1, 2.0);
	return 0;
}
