#include<iostream>
using namespace std;

//��������������������1�ĸ��� 
int main()
{
	int num = 0, count = 0, temp = 0;
	while (cin >> num)
	{
		count = 0;
		while (num != 0)
		{
			temp = num % 2;
			if (temp == 1)
			{
				count++;
			}
			num = num / 2;
		}
		cout << count << endl;	
	}
	return 0;
}

class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		int sum = 0;
		int left_sum = 0, left_min = 26;//��ߵ�����������������������ٵ�һ����ɫ��������
		int right_sum = 0, right_min = 26;//�ұ�
		for (int i = 0; i < n; i++)
		{
			if (left[i] * right[i] == 0)//���ĳ����ɫ��������һ������Ϊ0��Ҫȫ������
			{
				sum = sum + left[i] + right[i];
			}
			else
			{
				left_sum += left[i];
				right_sum += right[i];
				left_min = min(left[i], left_min);//����ߵ���С������
				right_min = min(right[i], right_min);//���ұߵ���С������
			}
		}
		sum = sum + min(left_sum - left_min + 1 , right_sum - right_min + 1) + 1;
		return sum;
	}
};