#include"student.h"
int num = 0;
int i = 0;
student st[100];    //ѧ������

/*****************************
*   ѧ��ͨѶ¼��Ϣ������    *
*****************************/

void student::input()
{
	fstream file;
	char ch = 'y';
	//�������ʽ���ļ�������Ѿ��д����ֵ��ļ�������ԭ������ȫ��ɾ����
	file.open("d://student.txt", ios::out);
	while (ch == 'y' || ch == 'Y')
	{
		cout << "please input student's message!" << endl;
		cout << "\t������������\t";
		cin >> st[i].name;
		cout << "\t�������Ա�\t";
		cin >> st[i].sex;
		cout << "\t�������������(��199109):";
		cin >> st[i].birth;
		cout << "\t������ѧУ��\t";
		cin >> st[i].school;
		cout << "\t������༶(����):\t";
		cin >> st[i].Class;
		cout << "\t������绰����:\t";
		cin >> st[i].tel;
		cout << "\t��������������:\t";
		cin >> st[i].box;
		cout << "\t������QQ��:\t";
		cin >> st[i].qq;
		cout << "\t�������ͥסַ:\t";
		cin >> st[i].address;
		file << st[i].name << "  " << st[i].sex << "    " << st[i].birth << "    "
			<< st[i].school << "  " << st[i].Class << "   " << st[i].tel << "   "
			<< st[i].box << "   " << st[i].qq << "   " << st[i].address << endl;
		cout << "\t���������?(Y/N):";
		cin >> ch;
		num += 1;
		i++;
	}
	cout << "\t��һ��������" << num << "����ѧ���ļ�¼��\n";
	file.close();
	menu();
}

/*****************************
*      ѧ��ͨѶ¼���޸�     *
*****************************/

void student::modify()
{
	fstream file;
	cout << "�޸������룬������(1):";
	int p;
	cin >> p;
	if (p != 1)
	{
		cout << "\t***�������!***" << endl;
		return;
	}
	else
	{
		cout << "������Ҫ�޸ĵ�ѧ����������\t";
		char pName[20];
		cin >> pName;
		for (i = 0; i < num; i++)
		{
			if (strcmp(st[i].name, pName) == 0)
				break;
			else
			{
				cout << "\tҪ�޸ĵ�ѧ�������ڣ�\n"; return;
			}
		}
		cout << "�������޸ĺ��������\t"; cin >> name;
		cout << "�������޸ĺ���Ա�\t"; cin >> sex;
		cout << "�������޸ĺ�ĳ������£�"; cin >> birth;
		cout << "�������޸ĺ��ѧУ��\t"; cin >> school;
		cout << "�������޸ĺ�İ༶(����)��\t"; cin >> Class;
		cout << "�������޸ĺ�ĵ绰���룺"; cin >> tel;
		cout << "�������޸ĺ���������룺"; cin >> box;
		cout << "�������޸ĺ��QQ�ţ�\t"; cin >> qq;
		cout << "�������޸ĺ�ļ�ͥסַ��"; cin >> address;
		strcpy(st[i].name, name);
		strcpy(st[i].sex, sex);
		strcpy(st[i].birth, birth);
		strcpy(st[i].school, school);
		st[i].Class = Class;
		strcpy(st[i].tel, tel);
		strcpy(st[i].box, box);
		strcpy(st[i].qq, qq);
		strcpy(st[i].address, address);
	}
	file.open("d://student.txt", ios::out);
	for (i = 0; i < num; i++)
	{
		file << st[i].name << "  " << st[i].sex << "    " << st[i].birth << "    "
			<< st[i].school << "  " << st[i].Class << "   " << st[i].tel << "   "
			<< st[i].box << "   " << st[i].qq << "   " << st[i].address << endl;
	}
	cout << "\t***�޸ĳɹ�***\n";
	menu();
	file.close();
}

/*****************************
*      ѧ��ͨѶ¼�Ĳ�ѯ     *
*****************************/

void student::search()
{
	char* inputname = new char[20];
	fstream file;
	file.open("d:\\student.txt", ios::in | ios::out);//�Զ��ķ�ʽ���ļ�
	cout << "\t1.��������ѯ " << "��2.���༶��ѯ" << endl;
	int a;
	cin >> a;
	if (a == 1)
	{
		cout << "\t��������Ҫ��ѯ��ѧ��������:";
		cin >> inputname;
		int flag = 0;
		for (i = 0; i <= num; i++)
		{
			if (strcmp(st[i].name, inputname) == 0)
			{
				cout << "\t����Ϊ" << inputname << "��ѧ������Ϣ����:" << endl;
				biaotou();
				cout << st[i].name << "  " << st[i].sex << "    " << st[i].birth << "    "
					<< st[i].school << "  " << st[i].Class << "   " << st[i].tel << "   "
					<< st[i].box << "   " << st[i].qq << "   " << st[i].address << endl;
				flag = 1;
			}
		}
		if (flag != 1)
			cout << "\t�Բ�����Ҫ���ҵ����ݲ����ڣ�";
		return;
	}
	else if (a == 2)
	{
		int flag2 = 0;
		cout << "\t��������Ҫ��ѯ��ѧ���İ༶:";
		int inputClass;
		cin >> inputClass;
		for (i = 0; i < num; i++)
		{
			if (st[i].Class == inputClass)
			{
				cout << "\t�༶Ϊ" << inputClass << "��ѧ������Ϣ����:" << endl;
				biaotou();
				cout << st[i].name << "  " << st[i].sex << "    " << st[i].birth << "    "
					<< st[i].school << "  " << st[i].Class << "   " << st[i].tel << "   "
					<< st[i].box << "   " << st[i].qq << "   " << st[i].address << endl;
				flag2 = 1;
			}
		}
		if (flag2 != 1)
			cout << "\t�Բ�����Ҫ���ҵ����ݲ����ڣ�" << endl;
	}
	file.close();
	menu();
}

/*****************************
*      ѧ��ͨѶ¼�����     *
*****************************/

void student::display()
{
	fstream file;
	cout << "\tѧ��ͨѶ¼��Ϣͳ�����£�" << endl;
	biaotou();
	//�����������ʽ���ļ����ļ��ɶ���д
	file.open("d:\\student.txt", ios::in | ios::out);
	for (i = 0; i < num; i++)
		file >> st[i].name >> st[i].sex >> st[i].birth >> st[i].school >> st[i].Class >> st[i].tel >> st[i].box >> st[i].qq >> st[i].address;
	file.close();
	for (i = 0; i < num; i++)
	{
		cout << st[i].name << "  " << st[i].sex << "    " << st[i].birth << "    "
			<< st[i].school << "  " << st[i].Class << "   " << st[i].tel << "   "
			<< st[i].box << "   " << st[i].qq << "   " << st[i].address << endl;
	}
	menu();
}

/*****************************
*      ѧ��ͨѶ¼��ɾ��     *
*****************************/

void student::deletes()
{
	fstream file;
	cout << "\t��ɾ����ѧ���������ǣ�";
	char pName[20];
	cin >> pName;
	for (int i = 0; i < num; i++)
	{
		if (strcmp(st[i].name, pName) == 0)
			break;
	}
	for (int j = i; j < num; j++)//��Ҫɾ����ѧ�������������һλ
	{
		student temp = st[j];
		if (j < num - 1)
		{
			st[j] = st[j + 1];
			st[j + 1] = temp;
		}
	}
	file.open("d:\\student.txt", ios::out);
	if (i < num)
	{
		num -= 1;
		cout << "\t\t����Ϊ" << pName << "��ѧ����ɾ����\n";
	}
	else
	{
		cout << "\tҪɾ����ѧ�������ڣ�\n";
	}
	for (i = 0; i < num; i++)
	{
		file << st[i].name << "  " << st[i].sex << "    " << st[i].birth << "    "
			<< st[i].school << "  " << st[i].Class << "   " << st[i].tel << "   "
			<< st[i].box << "   " << st[i].qq << "   " << st[i].address << endl;
	}
}

void student::qingkong()
{
	fstream file;
	file.open("d://student.txt", ios::out);
	num = 0;
	cout << "\t**ͨѶ¼����գ�**\n";
}

//********��ͷ**********
void student::biaotou()
{
	cout << "����    " << "�Ա�  " << "��������  " << "ѧУ    " << "�༶  "
		<< "�绰����     " << "��������  " << "QQ��      " << "��ͥסַ" << endl;
}

/*****************************
*      �� �� ѡ �� �� ��    *
*****************************/
void student::menu()
{

	while (1)
	{
		cout << endl;
		cout << "\t=zzia=zzia=zzia=zzia=zzia=zzia=\n";
		cout << "\t||      �����ߣ�������       ||\n";
		cout << "\t||      ��¼���¼��I/i��    ||\n";
		cout << "\t||      ���ѯ��¼��S/s��    ||\n";
		cout << "\t||      ���޸ļ�¼��M/m��    ||\n";
		cout << "\t||      ����ʾ��¼��D/d��    ||\n";
		cout << "\t||      ��ɾ����¼��X/x��    ||\n";
		cout << "\t||      ����ռ�¼��Q/q��    ||\n";
		cout << "\t||      ���˳�������E/e��    ||\n";
		cout << "\t||      �༶������1802       ||\n";
		cout << "\t||        ��ӭ����ʹ��       ||\n";
		cout << "\t=zzia=zzia=zzia=zzia=zzia=zzia=\n";
		cout << "�� ����������ѡ��I/i��S/s��M/m��D/d��X/x��Q/q��E/e�������ִ�Сд����";
		char ch;
		cin >> ch;
		switch (ch)
		{
		case'i':
		case'I':
			input(); break;
		case's':
		case'S':
			search(); break;
		case'm':
		case'M':
			modify(); break;
		case'd':
		case'D':
			display(); break;
		case'x':
		case'X':
			deletes(); break;
		case'q':
		case'Q':
			qingkong(); break;
		case'e':
		case'E':
			cout << "\tлл����ʹ��!" << endl;
			exit(0); break;
		default:
			cout << "\t����ѡ������!\n"; break;
		}
	}
}




