#include<iostream>
#include<string>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

#if 0
//��������
//ֻ��ͨ��70%
int main()
{
	string s;
	vector<string> v;
	int sum = 0;
	while (cin >> s)
	{
		sum++;
		v.push_back(s);
	}

	cout << sum << endl;
	int i = 0;
	while (i < v.size())
	{
		cout << v[i] << endl;
		i++;
	}
	return 0;
}
#endif

#if 0
//��������
int main()
{
	string s,tmp;
	vector<string> v;//�洢ÿ������
	getline(cin, s);//�����������ַ�����
	int start=0;//��¼ÿһ������ĳ�ʼλ��	
	int i = 0;
	while (i < s.size())
	{
		if (i<s.size() && s[i] == '"')
		{
			start = i;
			do {
				i++;
			} while (s[i] != '"');
			tmp = s.substr(start + 1, i - start-1);//��" "��������������ַ�������
			v.push_back(tmp);
			i += 2;//ֱ�������¸������ʼ�ַ�
		}
		if (i<s.size() && s[i] != '"')
		{
			start = i;
			while (i < s.size() && s[i] != ' ')
			{
				i++;
			}
			if (s[i] == ' ' || s[i] == '\0')
			{
				tmp = s.substr(start, i - start);
				v.push_back(tmp);
				i++;
			}
		}
	
	}
	cout << v.size() << endl;
	for (vector<string>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}
		
	return 0;
}
#endif

#if 0
//��ʯ��
int main() {
	int N, M;
	while (cin >> N >> M) 
	{
		vector<int> steps(M + 1, INT_MAX);
		steps[N] = 0;
		for (int i = N; i <= M; i++) 
		{
			if (steps[i] == INT_MAX) 
			{
				continue;
			}
			for (int j = 2; (j * j) <= i; j++) 
			{
				if (i % j == 0) 
				{
					if (i + j <= M) 
					{
						steps[i + j] = min(steps[i] + 1, steps[i + j]);
					}
					if (i + (i / j) <= M) 
					{
						steps[i + (i / j)] = min(steps[i] + 1, steps[i + (i / j)]);
					}
				}
			}
		}
		if (steps[M] == INT_MAX) 
		{
			steps[M] = -1;
		}
		cout << steps[M] << endl;
	}
	return 0;
}
#endif
