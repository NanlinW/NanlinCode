#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int getFirstUnFormedNum(vector<int> arr, int len) {
        int sum = 0, min = arr[0];
        for (int i = 0; i < len; ++i) {
            sum += arr[i];
            min = min < arr[i] ? min : arr[i];
        }
        vector<int> v(sum + 1, 0);
        for (int i = 0; i < len; ++i) {
            //{2�� 3�� 5}
            //i=0--d[10]=2 d[9]=2 d[8]=2 d[7]=2...d[2]=2
            //i=1--d[10]=5 d[9]=5...d[5]=5 d[4]=3 d[3]=3
            //i=2--d[10]=10 d[9]=8 d[8]=8 d[7]=7 d[6]=5 d[5]=5
            for (int j = sum; j >= arr[i]; --j) {
                //�����жϱ����������ܹ����������
                //��������ֻ��2��ʱ�򣬱������ش�2-10�����Է���2����ֵ
                //�������з���2��3��ʱ�򣬱������ش�5-10���Է���5��3-4����3��2ֻ�ܷ���2
                //�������з���2��3��5ʱ����������10����10��8-9����8��7����7��5-6����5...
                //dp[j-arr[i]]��˼�Ǳ�������Ϊjʱ������Ѿ�������arr[i]���������ܷ��õ��������
                if (v[j] < v[j - arr[i]] + arr[i]) {
                    v[j] = v[j - arr[i]] + arr[i];
                }
            }
        }
        //��󵱳���Ϊnʱ�������������Ϊn����Ϊ����󲻿����
        for (int i = min; i <= sum; ++i) {
            if (i != v[i]) {
                return i;
            }
        }
        return sum + 1;
    }
};


//�мٱ�
int main()
{
    int n = 0, sum;
    while (cin >> n)
    {
        int count = 0;
        while (n > 1)
        {
            n = n / 3 + 1 - (n % 3 ^ 3) / 3;
            count++;
        }
        cout << count << endl;
    }
    return 0;
}