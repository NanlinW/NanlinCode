class person
{
public:
	void show()//�����Ͷ���ȫ������������
	{
		cout << _name << "-" << _sex << "-" << _age << endl;
	}
public:
	char* _name;
	char* _sex;
	int _age;
};

//person.h�ļ�
class person
{
public:
	void show()
public:
	char* _name;
	char* _sex;
	int _age;
};

//person.cpp
#include"person.h"
void person::show()
{
	cout << _name << "-" << _sex << "-" << _age << endl;
}
