#include<iostream>
#include<map>
using namespace std;

//int TestAuto()
//{
//	return 10;
//}

int main()
{
	//std::map<std::string, std::string> dict;
	//std::map<std::string, std::string>::iterator it = dict.begin();
	//auto it = dict.begin();
	//cout << typeid(it).name() << endl;
	//int a = 10;
	//auto b = a; //�Ƶ���bΪint
	//auto c = 'a'; //�Ƶ���cΪchar
	//auto d = TestAuto(); //��TestAuto���ص�����һ������int
	//cout << typeid(b).name() << endl;
	//cout << typeid(c).name() << endl;
	//cout << typeid(d).name() << endl;

	//auto e; �޷�ͨ�����룬ʹ��auto�������ʱ���������г�ʼ��
	//int x = 10;
	//auto a = &x;
	//auto* b = &x;
	//auto& c = x;
	//cout << typeid(a).name() << endl;
	//cout << typeid(b).name() << endl;
	//cout << typeid(c).name() << endl;
	//auto a = 1, b = 2;
	//auto c = 3, d = 4.0; // ���д�������ʧ�ܣ���Ϊc��d�ĳ�ʼ�����ʽ���Ͳ�ͬ
	//cout << typeid(a).name() << endl;
	//cout << typeid(b).name() << endl;

		//int array[] = { 1, 2, 3, 4, 5 };

		//for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)//��ͨѭ��
		//	array[i] *= 2;

		//for (int* p = array; p < array + sizeof(array) / sizeof(array[0]); ++p)//ָ�����

		//	cout << *p << endl;

		int array[] = { 1, 2, 3, 4, 5 };
		for (auto e : array)//auto& e��ʾ���ã���ʱe��array�ı��������Խ����޸�
			e *= 2;
		for (auto e : array)//auto e��ʾe��a�ķ�Χ�ڵ����������޸�������
			cout << e << endl;

	return 0;
}