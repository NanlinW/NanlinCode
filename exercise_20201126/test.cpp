#include<iostream>
#include<string>
#include<vector>
using namespace std;

#if 0
//ͳ�ƻ���
bool isPalindrome(string s)
{
	if (s.size() == 1)
		return true;
	int start = 0;
	int end = s.size() - 1;
	while (start < end)
	{
		if (s[start++] != s[end--])
			return false;
	}
	return true;
}

int main()
{
	string A,B,C,temp;
	cin >> A;
	cin >> B;
	int len = A.size();
	int num = 0;
	for (int i = 0; i < len+1; i++)//A��β��Ҳ�ܲ壬len+1
	{
			temp = A;
			C = temp.insert(i,B);
			if (isPalindrome(C))
			{
				num++;
			}
	}
	cout << num << endl;
	return 0;
}
#endif

//��������
int main()
{
	int n, max;
	cin >> n;
	vector<int> list(n, 0), dp(list);
	for (int i = 0; i < n; i++)   //��������
		cin >> list[i];
	max = dp[0] = list[0];
	for (int i = 1; i < n; i++)   //�����������ģ����ֻ��Ҫ���¶�
	{                                     //���߼��ɣ�֮ǰ��������һ����ͬ
		if (list[i] + dp[i - 1] > list[i])      //�����һ�Խ����ϵ����͸���
			dp[i] = list[i] + dp[i - 1];       //�����Ӧλ��
		else
			dp[i] = list[i];                       //���򣬼�Ϊ���������
		if (max < dp[i]) max = dp[i];     //Ѱ������������

	}
	cout << max << endl;
	return 0;
}