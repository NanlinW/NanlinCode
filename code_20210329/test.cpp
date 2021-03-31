#include <iostream>
using namespace std;

class One
{
public:
	One() {
		cout << "constructor\n";
	}
private:
	~One() {
		cout << "destructor\n";
	}
	friend void Destroy(One* one);
};
void Destroy(One* one)
{
	if (one != nullptr) {
		delete one;
	}
}

int main()
{
	     //One one; // �����ǲ��еģ����ܷ�����������
		//One* one;//ok
		One* one = new One(); //ok
		return 0;
}
