#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/*
����һ������Ϊn���ַ������ַ�����ÿһ��Ԫ�ض���0~9֮���,���������������˳��Ϊ1807���ǡ��õġ��������ġ��õġ������еĳ���
�������� 18800007777000007
����õġ������г���Ϊ �� 13��1880000000007��
*/
//1
//int len(string s)
//{
//	int res = 0;
//	if (s[0] != '1')
//	{
//		return 0;
//	}
//	int i = 0;
//	int start = 0;
//	while(i < s.size() && s[i] == '1')
//	{
//		res++;
//		i++;
//	}
//	return res;
//}


//int main()
//{
//	string s;
//	int res = len(s);
//	cout << res << endl;
//	return 0;
//}

/*2��ҫ����
��iʱ�������Ϸ�õ�����Ϸ�ķ�����iʱ��û��ɵ���Ϸ��ȥ����Ϸ�ķ�����������÷�
��һ������T������
�ڶ�������n����Ϸ
������n����Ϸ�ֱ�ʼ��ʱ��
������n����Ϸ�����ķ���
����
����
1
3
3 1 1
3 6 9
���
6
���ͣ�
ʱ��1ʱ���9�ֵ���Ϸ���÷ּ�Ϊ9�������޷����6�ֵ���Ϸ����6�֣��÷ּ�Ϊ3��ʱ��3���3�ֵ���Ϸ���÷ּ�Ϊ6
����ܵ÷�6
*/
int main()
{
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		multimap<int, int> m;
		vector<int> time(n);
		for (int i = 0; i < n; i++)
		{
			cin >> time[i];
		}
		vector<int> score(n);
		for (int i = 0; i < n; i++)
		{
			cin >> score[i];
		}
		for (int i = 0; i < n; i++)
		{
			m.insert(pair<int,int>(time[i], score[i]));
		}
		//�Ʒ�
		int sum = 0;
		multimap<int, int>::iterator it;
		sort(time.begin(), time.end());
		vector<int>::iterator new_end = unique(time.begin(), time.end());
		time.erase(new_end, time.end());
		for (int i = 0; i <time.size() ; i++)
		{
			int temp = 0,max = 0;
			vector<int> tmp;
			for (it = m.lower_bound(time[i]); it != m.upper_bound(time[i]); it++)
			{
				temp = it->second;
				tmp.push_back(temp);
			}
			sort(tmp.begin(), tmp.end());
			max = tmp[tmp.size() - 1];
			for (int i = tmp.size() - 2; i >= 0; i--)
			{
				max = max - tmp[i];
			}
			sum = sum + max;
		}
		cout << sum << endl;
	}
	return 0;
}




/*
�ж�һ��������[L, R]֮��ƽ����������
ƽ����ָ���������λ��ӵĺ� �� ż��λ��ӵĺ� ���
����132����һ��ƽ���� 1+2 == 3
*/
//3
//int judge(string s)
//{
//	int suma = 0;//����λ��
//	int sumb = 0;//ż��λ��
//	for (int i = 1; i < s.size(); i += 2)
//	{
//		if (i < s.size())
//		{
//			suma += s[i] - '0';
//		}
//	}
//	for (int i = 0; i < s.size(); i += 2)
//	{
//		if (i < s.size())
//		{
//			sumb += s[i] - '0';
//		}
//	}
//	if (suma == sumb)
//	{
//		return 1;
//	}
//	return 0;
//}
//
//
//int judge2(string s)
//{
//	
//}
////10 11 12 13 14 15 n=6 
//int banlancesum(int start, int end)
//{
//	int sum = 0;
//	int n = end - start + 1;
//	vector<string> s(n);
//	for (int i = 0, j = start; i < n; i++, j++)
//	{
//		string temp;
//		temp = to_string(j);
//		s[i] = temp;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		int res = judge(s[i]);
//		if (res == 1)
//		{
//			sum++;
//		}
//	}
//	return sum;
//}
//
//int main()
//{
//	int start, end;
//	cin >> start >> end;
//	int res = banlancesum(start, end);
//	cout << res << endl;
//	return 0;
//}