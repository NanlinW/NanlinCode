//����������
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#if 0
int main()
{
	int i = 0,n;
	vector<int> A(100000, 0);

	cin >> n;
	while (i < n)
	{
		cin >> A[i];
		i++;
	}

	int sum = 0, j = 0;
	while (j<n)
	{
		if (A[j] < A[j + 1])//�жϵ���������
		{
			while (j < n && A[j] <= A[j + 1])
			{
				j++;
			}
			sum++, j++;
		}

		else if (A[j] == A[j + 1])
		{
			j++;
		}

		else if (A[j] > A[j + 1])
		{
			while (j < n && A[j] >= A[j + 1])
			{
				j++;
			}
			sum++, j++;
		}
	}

	cout << sum << endl;
	return 0;
}
#endif

#if 0
//�����ַ���
// ����1��cin��ȡstringʱ�Զ��ᱻ�ո�ָ���������һ���ַ����洢����������� 
//int main()
//{
//	string s1, s2;
//	cin >> s2;
//	while (cin >> s1)
//		s2 = s1 + " " + s2;
//	cout << s2 << endl;
//	return 0;
//}

//�������ַ������ٷ�תÿһ������
int main()
{
	string s;
	getline(cin, s);
	int i = 0,start=0;
	int left = 0, right = 0;
	reverse(s.begin(), s.end());//�����ַ���
	while (i < s.size())//��תÿһ������
	{
		start = i;
		while (i < s.size() && s[i] != ' ')
		{
			i++;
		}
		left = start, right = i - 1;
		while (left < right)
		{
			swap(s[left], s[right]);
			left++;
			right--;
		}
		while (i < s.size() && s[i] == ' ')
		{
			i++;
		}
	}

	cout << s << endl;

	return 0;
}
#endif

//������Ʊ�����ʱ��
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int i = 0, max = 0;
		while (i < prices.size())
		{
			for (int j = i + 1; j < prices.size(); j++)
			{
				if (prices[j] - prices[i] > max)
				{
					max = prices[j] - prices[i];
				}
			}
			i++;
		}

		return max;
	}
};