#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//��Ʒ����
//int ticketsum(int num)//һ������Ҫ�������޸ľ��Ӯ
//{
//	int res = 0;
//	int prev = 0;//��¼num��һ�ε�ֵ
//	int now = 0;
//	for (int i = 1; num > 0; i += 2)
//	{
//		prev = num;
//		num -= i;
//	}
//	now = (-1) * num;
//	if (now > prev)
//	{
//		res = prev;
//	}
//	else
//	{
//		res = now;
//	}
//	return res;
//}
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<int> a;
//	for (int i = 0; i < n; i++)
//	{
//		int tmp = 0;
//		cin >> tmp;
//		a.push_back(tmp);
//	}
//	int count = 0;//�ۼ����ٵ��޸ľ�
//	vector<int> ticket;//��¼ÿ������Ҫ�������޸ľ�
//	for (int i =0 ; i < n; i++)
//	{
//		ticket.push_back(ticketsum(a[i]));
//	}
//	sort(ticket.begin(), ticket.end());
//	for (int i = 0; i < n / 2; i++)
//	{
//		count += ticket[i];
//	}
//	cout << count << endl;
//	return 0;
//}

//������Ϸ
int main()
{
	int n = 0;
	cin >> n;
	vector<vector<int>> arr(n);
	for (int i = 0; i < n; i++)
	{
		arr[i].resize(2, 0);
	}
	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		cin >> temp;
		arr[i][0] = temp; //a[i]
	}
	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		cin >> temp;
		arr[i][1] = temp; //b[i]
	}
	int min = INT_MAX;//��¼��Сb[i] + b[j] + b[k]
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				if (arr[i][0] <= arr[j][0] && arr[j][0] <= arr[k][0] && arr[i][0] <= arr[k][0])
				{
					int tmp = 0;
					tmp = arr[i][1] + arr[j][1] + arr[k][1];
					if (tmp < min)
					{
						min = tmp;
					}
				}
			}
		}
	}

	cout << min << endl;
	return 0;
}