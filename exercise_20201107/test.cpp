////�ҳ��ַ����е�һ��ֻ����һ�ε��ַ�
//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	string str;
//	while (getline(cin, str))
//	{
//		for (int i = 0; i < str.size(); i++)
//		{
//			if (str.find_first_of(str[i]) == str.find_last_of(str[i]))
//			{
//				cout << str[i] << endl;
//				break;
//			}
//			if (i == str.size() - 1)
//			{
//				cout << -1 << endl;
//			}
//		}
//	}
//
//	return 0;
//}
//
////��ת�ַ���
//class Solution {
//public:
//	void reverseString(vector<char>& s) {
//		int i = 0, j = s.size() - 1;
//		for (; i < s.size() / 2; i++, j--)
//		{
//			swap(s[i], s[j]);
//		}
//	}
//};

//�ַ������һ�����ʵĳ���
//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	string str;
//	getline(cin, str);
//	//int i = str.find_last_of(' ');
//	//cout << str.size()-i-1 << endl;
//	reverse(str.begin(), str.end());
//	int i = str.find_first_of(' ');
//	cout << i << endl;
//
//	return 0;
//}

//�ַ����еĵ�һ��Ψһ�ַ�
//class Solution {
//public:
//	int firstUniqChar(string s)
//	{
//
//		for (int i = 0; i < s.size(); i++)
//		{
//			if (s.find_first_of(s[i]) == s.find_last_of(s[i]))
//			{
//				return i;
//				break;
//			}
//
//		}
//
//
//		return -1;
//	}
//};
#include<iostream>
#include<string>
using namespace std;
void main()

{
	string s1 = "hello world";
	string s2 = "change world";
	string::iterator it = s1.begin();
	swap(s1, s2);
	while (it != s1.end())
		cout << *it;

	cout << endl;

}