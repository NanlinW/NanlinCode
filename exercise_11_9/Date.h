#include<iostream>//ͷ�ļ�������
using namespace std; //c++����������
class Date
{
	friend std::ostream& operator<<(std::ostream&, Date&);//�������
	friend std::istream& operator>>(std::istream&, Date&); //��������
public:
	Date();//�յĹ��캯��
	Date(int y, int m, int d);
	void setDate(int y, int m, int d);
	int getyear()
	{
		return year;
	}
	void addDay();
	void subtractDay();
	void print();
private:
	int year;
	int day;
	int month;

};

