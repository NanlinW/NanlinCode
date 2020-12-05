#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#pragma warning(disable:4996)
using namespace std;

//class string
//{
//public:
//	string(const char* str = "")
//	{
//		if (str == nullptr)
//		{
//			str = "";
//		}
//		_str = new char[strlen(str) + 1];
//		strcpy(_str, str);
//	}
//
//	string(const string& s)
//		:_str(new char[strlen(s._str)+1])
//	{
//		strcpy(_str, s._str);
//	}
//
//	string& operator=(const string& s)
//	{
//		if (this != &s)
//		{
//			if (_str != nullptr)
//			{
//				delete[] _str;
//				_str = nullptr;
//			}
//			_str = new char[strlen(s._str) + 1];
//			strcpy(_str, s._str);
//		}
//		return *this;
//	}
//
//	~string()
//	{
//		if (_str)
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//	}
//
//private:
//	char* _str;
//};


//���ַ���ת��Ϊ����
//class Solution {
//public:
//	int StrToInt(string str) {
//		const int len = str.length();
//		if (len == 0) return 0;
//		int i = 0;
//		while (i < len && str[i] == ' ')//�ų��ַ���ǰ��Ŀո�
//		{
//			i++;
//		}
//		if (i == len) return 0;
//		if (!isdigit(str[i]) && str[i] != '+' && str[i] != '-')
//		{
//			return 0; //��ͷ�������ֻ�Ӽ���ֱ���˳�
//		}
//		bool neg = str[i] == '-' ? true : false;//�ж�������������������0,����0
//		i = isdigit(str[i]) ? i : i + 1; //������λ��ʼ
//		long long num = 0;
//
//		while (i < len && isdigit(str[i]))
//		{
//			num = num * 10 + (str[i] - '0');//���ַ�����λת����int
//			i++;
//			if (neg == 0 && num > INT_MAX)//�������������ҳ���int��Χ
//			{
//				num = INT_MAX;
//				break;
//			}
//			if (neg != 0 && num > (1L + INT_MAX))//�������Ǹ����ҳ���int��Χ
//			{
//				num = 1 + INT_MAX;
//				break;
//			}
//		}
//		if (i != len) return 0;
//		if (neg != 0)
//		{
//			return -num;
//		}
//		else return num;
//
//	}
//};

//�ַ������
//class Solution {
//public:
//	string multiply(string num1, string num2) {
//		if (num1 == "0" || num2 == "0") return "0";//����������һ��0����ֱ�ӷ���0
//		
//		int size = num1.length() + num2.length();
//		//������˵Ľ�����λ��Ϊnum1��num2λ��֮��
//		int *res=new int[size];
//		for (int i = num1.length() - 1; i >= 0; i--)
//		{
//			int n1 = num1[i] - '0';
//			for (int j = num2.length() - 1; j >= 0; j--)
//			{
//				int n2 = num2[j] - '0';
//				int sum = (res[i + j + 1] + n1 * n2);
//				res[i + j + 1] = sum % 10;
//				res[i + j] += sum / 10;
//			}
//		}
//		string result;
//		result.reserve(size + 1);
//		for (int i = 0; i < size; i++) //�崦ǰ���0
//		{
//			if (i == 0 && res[i] == 0) continue;
//			result.push_back(res[i]);
//		}
//
//		return result;
//
//	}
//};

class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0") {
			return "0";
		}
		int size = num1.length() + num2.length();
		//������˵Ľ�����λ��Ϊnum1��num2λ��֮��
		vector<int> res(size,0);
		for (int i = num1.length() - 1; i >= 0; i--) //��ʽ���
		{
			int n1 = num1[i] - '0';
			for (int j = num2.length() - 1; j >= 0; j--) {
				int n2 = num2[j] - '0';
				int sum = (res[i + j + 1] + n1 * n2);
				res[i + j + 1] = sum % 10;
				res[i + j] += sum / 10;
			}
		}

		string result="";
		bool flag = true;
		for (int i = 0; i < res.size(); i++) {
			if (res[i] != 0 || !flag) {
				flag = false;
				res.push_back(res[i] + '0');
			}
		}
	
		return result;
	}
};



/*
//FFT��
class Solution {
public:
	using CP = complex <double>;

	static constexpr int MAX_N = 256 + 5;

	double PI;
	int n, aSz, bSz;
	CP a[MAX_N], b[MAX_N], omg[MAX_N], inv[MAX_N];

	void init() {
		PI = acos(-1);
		for (int i = 0; i < n; ++i) {
			omg[i] = CP(cos(2 * PI * i / n), sin(2 * PI * i / n));
			inv[i] = conj(omg[i]);
		}
	}

	void fft(CP* a, CP* omg) {
		int lim = 0;
		while ((1 << lim) < n) ++lim;
		for (int i = 0; i < n; ++i) {
			int t = 0;
			for (int j = 0; j < lim; ++j) {
				if ((i >> j) & 1) t |= (1 << (lim - j - 1));
			}
			if (i < t) swap(a[i], a[t]);
		}
		for (int l = 2; l <= n; l <<= 1) {
			int m = l / 2;
			for (CP* p = a; p != a + n; p += l) {
				for (int i = 0; i < m; ++i) {
					CP t = omg[n / l * i] * p[i + m];
					p[i + m] = p[i] - t;
					p[i] += t;
				}
			}
		}
	}

	string run() {
		n = 1;
		while (n < aSz + bSz) n <<= 1;
		init();
		fft(a, omg);
		fft(b, omg);
		for (int i = 0; i < n; ++i) a[i] *= b[i];
		fft(a, inv);
		int len = aSz + bSz - 1;
		vector <int> ans;
		for (int i = 0; i < len; ++i) {
			ans.push_back(int(round(a[i].real() / n)));
		}
		// �����λ
		int carry = 0;
		for (int i = ans.size() - 1; i >= 0; --i) {
			ans[i] += carry;
			carry = ans[i] / 10;
			ans[i] %= 10;
		}
		string ret;
		if (carry) {
			ret += to_string(carry);
		}
		for (int i = 0; i < ans.size(); ++i) {
			ret.push_back(ans[i] + '0');
		}
		// ����ǰ����
		int zeroPtr = 0;
		while (zeroPtr < ret.size() - 1 && ret[zeroPtr] == '0') ++zeroPtr;
		return ret.substr(zeroPtr, INT_MAX);
	}

	string multiply(string num1, string num2) {
		aSz = num1.size();
		bSz = num2.size();
		for (int i = 0; i < aSz; ++i) a[i].real(num1[i] - '0');
		for (int i = 0; i < bSz; ++i) b[i].real(num2[i] - '0');
		return run();
	}
};

*/

int main()
{
	Solution a;
	string s1("999");
	string s2("99");

	string sum;
	sum=a.multiply(s1,s2);
	cout << sum << endl;
	return 0;
}