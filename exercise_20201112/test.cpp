#include<iostream>
#include<assert.h>
#include<string.h>
#include<string>
#pragma warning(disable:4996)
using namespace std;

/*
//string���ʵ��
class string
{
public:

	string(const char* str = "")//����
	{
		if (nullptr == str)//strΪnullptr���ж�Ϊ�Ƿ�
		{
			assert(false);
			return;
		}
		//if (nullptr == str)
		//{
		//	 str = "";
		//}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	string(const string& s)//��������
		:_str(new char[strlen(s._str)+1])
	{
		strcpy(_str, s._str);
	}

	//string(const string& s)//�ִ��濽������
	//	:_str(nullptr)
	//{
	//	string strtmp(s._str);
	//	swap(_str, strtmp._str);
	//}

	string& operator=(const string& s)//��ֵ //���ݵ��Ǳ���
	{
		if (this != &s)
		{
			char* pstr = new char[strlen(s._str) + 1];
			strcpy(pstr, s._str);
			delete[] _str;
			_str = pstr;
		}

		return *this;
	}

	
	//string& operator=(const string s)//�����β�,�����Ը���
	//{
	//	swap(_str, s._str);
	//	return *this;
	//}
	

	~string()//����
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}

private:
	char* _str;
};

*/

/*125. ��֤���Ĵ�
class Solution {
public:
	bool isPalindrome(string s) {
		if (s.empty())//�մ�Ҳ�ǻ��Ĵ�
		{
			return true;
		}
		if (s.size() == 1)
		{
			return true;
		}

		int left = 0;
		int right = s.size() - 1;
		while (left < right)
		{
			//1.�ж��Ƿ�Ϊ��ĸ
			while (left != right)
			{
				if (isalpha(s[left])) break;

				++left;
			}

			while (left < right)
			{
				if (isalpha(s[right])) break;
				--right;
			}
			//2.�Ƚ��Ƿ���ͬ
			if (left < right)
			{
				if ((s[left] + 32 - 'a') % 32 != (s[right] + 32 - 'a') % 32)//������ĸ��Сд
				{
					return false;
				}

			}
			left++;
			right--;
		}
		//3.ѭ��ִ�������֤���ǻ��Ĵ�
		return true;
	}
};
*/

/*
//����һ���ַ���������Ҫ��ת�ַ�����ÿ�����ʵ��ַ�˳��ͬʱ�Ա����ո�͵��ʵĳ�ʼ˳��
class Solution {
public:
	string reverseWords(string s) {
		int lenth = s.size();
		int i = 0;
		while (left < right)//ʹ��ѭ����תһ���ַ�������Ķ������
		{
			int start = i;
			while (i < lenth && s[i] != ' ')//i�ƶ����ո�
			{
				i++;
			}
			int left = start;
			int right = i - 1;
			while (left < right)//��תһ������
			{
				swap(s[left], s[right]);
				++left;
				--right;
			}
			while (i < lenth && s[i] == ' ')//��i�Ƶ��¸����ʳ�ʼ��
			{
				i++;
			}
		}

		return s;
	}
};
*/

/*
//����һ���ַ��� s ��һ������ k������Ҫ�Դ��ַ�����ͷ�����ÿ�� 2k ���ַ���ǰ k ���ַ����з�ת
class Solution {
public:
	string reverseStr(string s, int k) {
		for (int i = 0; i < s.size(); i += (2 * k))//���ַ���ÿ��2k���ַ�����һ��
		{
			if (i + k <= s.size())//���ڵ���k��С��2k�ͽ��ÿ�ǰk���ַ���ת
			{
				reverse(s.begin() + i, s.begin() + i + k);
				continue;
			}
			//����k���ַ���ȫ����ת
			reverse(s.begin() + i, s.begin() + s.size());
		}
		return s;
	}
};
*/

/*
//���������ַ�����ʽ�ķǸ����� num1 ��num2 ���������ǵĺ�
class Solution {
public:
	string addStrings(string num1, string num2) {
		int size1 = num1.size();
		int size2 = num2.size();
		if (size1 < size2)
		{
			num1.swap(num2);
			swap(size1, size2);
		}
		string strRet;
		strRet.reserve(size1 + 1);//��Ӻ�������ȴ������һλ
		int cstep = 0;//��λ1
		int cret = 0;//��ӵ�ǰλ��strRet

		for (size_t i = 0; i < size1; i++)
		{
			cret = num1[size1 - i - 1] - '0' + cstep;//����֮ǰ����λcstep
			cstep = 0;
			if (i < size2)
			{
				cret += num2[size2 - i - 1] - '0';//�����ַ�����ͬλ�ϵ������
			}
			if (cret >= 10)
			{
				cret -= 10;//ֻ����λ
				cstep = 1;//��Ӵ���10���һλ
			}
			strRet += cret + '0';
		}
		if (cstep)
		{
			strRet += '1';
		}

		reverse(strRet.begin(), strRet.end());

		return strRet;
	}
};
*/

//��һ���ַ���ת����һ��������Ҫ����ʹ���ַ���ת�������Ŀ⺯���� ��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0
int main()
{
	Solution a;
	string s1("999");
	string s2("99");
	string s3 ;
	s3=a.addStrings(s1, s2);
	cout << s3 << endl;
	return 0;
}



