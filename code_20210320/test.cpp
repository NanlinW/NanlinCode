#include <iostream>
#include <string>
#include <vector>
using namespace std;
//����һ����飬ÿ���������id���ַ�����ӳ�䣬��������һ����飬Ҫ���ҳ��µĴ������ϵĴ����diff��ϵ��diffҪ�����£�
//1��id��ͬ���ַ�����ͬ������������Ϊ��ͬ
//2��id��ͬ�����ַ�����ͬ�����modify+id
//3���µĴ���id���ϵĴ���id�в����ڵģ���Ϊ���������add+id
//4���ϵĴ���id���µĴ���id�в����ڵģ���Ϊɾ�������delete+id
//��������
//��һ�д����ϵĴ��飬�ڶ��д����µĴ���
//ÿһ����id - �ַ�������ϣ���������Զ��ŷָ�
//�磺1 - a, 2 - b, 3 - c
//�������
//һ���ַ��������������ַ��������ֱ��ʹ��string��compareTo�����Ƚϴ�С���ɣ��Զ��ŷָ����磺add - 2, delete - 22
/*
int func2(string a1, string a2)//�Ƚ������ַ����Ƿ����
{
	int i = 0;
	if (a1.size() != a2.size())
	{
		return 1;
	}
	while (i < a1.size())
	{
		if (a1[i] != a2[i])
		{
			return 1;
		}
		i++;
	}
	return 0;
}

void func(vector<string> arr1, vector<string> arr2)
{
	int len1 = arr1.size(), len2 = arr2.size();
	int min = 0;
	if (len1 > len2)
	{
		min = len2;
	}
	else
	{
		min = len1;
	}
	vector<string> res;
	for (int i = 0; i < min; i++)
	{
		int flag = 0;
		string tmp = "modify-";
		flag = func2(arr1[i], arr2[i]);
		if (flag == 1)
		{
			tmp += (i + 1) + '0';
			res.push_back(tmp);
		}
	}
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i];
		if (i != res.size() - 1 || len1 != len2)
		{
			cout << ",";
		}
	}
	if (len1 > len2)
	{
		for (int i = len2 + 1; i <= len1; i++)
		{
			cout << "delete-" << i;
			if (i != len1)
			{
				cout << ",";
			}
		}
	}
	else
	{
		for (int i = len1 + 1; i <= len2; i++)
		{
			cout << "add-" << i;
			if (i != len2 )
			{
				cout << ",";
			}
		}
	}
}



int main()
{
	string s1;
	cin >> s1;
	string s2;
	cin >> s2;
	vector<string> arr1;
	for (int i = 0; i < s1.size(); i++)
	{
		int start = i;
		string tmp = "";
		while (i < s1.size() && s1[i] != ',' )
		{
			i++;
		}
		tmp = s1.substr(start, i - start);
		arr1.push_back(tmp);
	}
	vector<string> arr2;
	for (int i = 0; i < s2.size(); i++)
	{
		int start = i;
		string tmp = "";
		while (i < s2.size() && s2[i] != ',')
		{
			i++;
		}
		tmp = s2.substr(start, i - start);
		arr2.push_back(tmp);
	}
	func(arr1, arr2);
	return 0;
}

*/

int main()
{
	int n = 0;
	cin >> n;
	vector<vector<int>> arr(n);
	for (int i = 0; i < n; i++)
	{
		arr[i].resize(2);
		scanf_s("%d,%d", &arr[i][0], &arr[i][1]);
	}
	int time = 0;
	int in = 0;//��ʼ
	int out = 0;//����
	for (int i = 0; i < n; i++)
	{
		if (arr[i][0] >= out)
		{
			in = arr[i][0];
			out = in + arr[i][1];
			time += (out - in);
		}
		else
		{
			in = out;
			out = in + arr[i][1];
			time += (out - arr[i][0]);
		}
	}
	cout << time << endl;
	return 0;
}