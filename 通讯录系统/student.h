#if !defined _STUDENT_H_
#define _STUDENT_H_
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

class student
{
public:
	void input();       //����
	void search();      //��ѯ
	void modify();      //�޸�
	void display();     //���
	void deletes();     //ɾ��
	void qingkong();    //���
	void menu();        //�˵�ѡ��
	void biaotou();     //��ͷ
private:
	char name[20];      //����  
	char sex[4];        //�Ա�
	char birth[10];     //��������
	char school[20];    //ѧУ
	int Class;          //�༶
	char tel[15];       //�绰����
	char box[10];       //��������
	char qq[15];        //QQ��
	char address[20];   //��ͥסַ
};
#endif
