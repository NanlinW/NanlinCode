#include<iostream>
using namespace std;
int main() {
	int ch;
	int nline = 0, nword = 0, nch = 0;
	int isword = 0;
	cout << "����һ���ı�(�޿���):" << endl;
	do {
		ch = cin.get();
		if (ch == '\n') nline++;
		if (ch != ' ' && ch != '\t' && ch != '\n' && ch != EOF) {
			if (!isword) nword++;
			nch++;
			isword = 1;
		}
		else isword = 0;
	} while (ch != EOF);
	cout << "����:" << nline << endl;
	cout << "������:" << nword << endl;
	cout << "�ַ���:" << nch << endl;
	return 0;
}
