//�ҳ�һ���ַ���������ظ��Ӵ� 
#include <iostream>
#include <string>
using namespace std;

string maxlist(string arr)
{
	int max = 0;
	string res;
	string temp;//��ʱ�����ظ��Ӵ�
	//���ظ��Ӵ�
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr.size(); j++)
		{
			
		}
	}
	//��һ��max�������Ӵ��ĳ���
	if (temp.size() > max)
	{
		max = temp.size();
		res = temp;
	}
	temp = "";

	return res;
}

int main()
{
	string arr;
	cin >> arr;
	string res = maxlist(arr);
	cout << res << endl;
	return 0;
}