#include <iostream>
using namespace std;

// ֻ���ڶ���
class HeapOnly
{
public:
	static HeapOnly* GetHeapObj()
	{
		HeapOnly* p = new HeapOnly;
		return p;
	}

private:
	HeapOnly()
	{
		cout << "HeapOnly()" << endl;
	}

	// C++98 ֻ������ʵ��+������˽��
	//HeapOnly(const HeapOnly& hp);

	// C++11
	HeapOnly(const HeapOnly& hp) = delete;
};

//class StackOnly
//{
//public:
//	static StackOnly CreateObject()
//	{
//		return StackOnly();
//	}
//private:
//	StackOnly()
//	{}
//};

class StackOnly
{
public:
	StackOnly() {}
private:
	// ����ר����operator new��delete�������Ҳ�ʵ�֣����û�취new��
	void* operator new(size_t size);
	void operator delete(void* p);
};

// C++98 ���ܱ��̳С�˽�������಻�ɼ� + ����Ĺ��캯��������ø���Ĺ��캯��
class NonInherit
{
public:
	static NonInherit GetInstance()
	{
		return NonInherit();
	}
private:
	NonInherit()
	{}
};

class Inherit : public NonInherit  // �������๹�캯�����趨
{};

//class A  final   // �����࣬���ܱ��̳�
//{
//	// ....
//};

//class InheritA : public A
//{
//};


//int main()
//{
//	//HeapOnly hp1;				// ջ
//	//static HeapOnly hp2;		// ���ݶ�
//	//HeapOnly* p = new HeapOnly; // ��
//
//	HeapOnly* p1 = HeapOnly::GetHeapObj();
//	//HeapOnly copy1(*p1);
//	//static HeapOnly copy2(*p1);
//
//	//StackOnly so = StackOnly::CreateObject();
//	StackOnly so1;
//	//StackOnly* p2 = new StackOnly; // operator new + ���캯��
//
//	//Inherit ih;
//
//
//	return 0;
//}

// ������Ψһ��ʵ������
// ���� -�� һ������Ҫ�ԣ�Ҳ����һ��ʼ(main����֮ǰ)�ʹ�������
//class Singleton
//{
//public:
//	static Singleton& GetInstance()
//	{
//		return _sInst;
//	}
//
//private:
//	// ���캯��˽�л�
//	Singleton()
//	{}
//
//	Singleton(const Singleton&) = delete;
//
//	static Singleton _sInst;
//};
//
//// �����ھ�̬��
//Singleton Singleton::_sInst; // main����֮ǰ�ʹ�����ʼ�����ʵ������
//
//int main()
//{
//	cout << &Singleton::GetInstance() << endl;
//	cout << &Singleton::GetInstance() << endl;
//	cout << &Singleton::GetInstance() << endl;
//	cout << &Singleton::GetInstance() << endl;
//
//	// ���߳�������Singleton::GetInstance()����û���̰߳�ȫ�����⣿
//	// û���̰߳�ȫ�����⣬��Ϊʵ������Ĵ�����main����֮ǰ
//
//	return 0;
//}

// ���� -�� ����֢�����һ�̣���һ�ε���GetInstanceʱ����ȥ��������
#include <vector>
#include <thread>
#include <mutex>

class Singleton
{
public:
	static Singleton& GetInstance()
	{
		// ˫��������Ч������
		if (_spInst == nullptr)
		{
			_smtx.lock();
			if (_spInst == nullptr)
			{
				_spInst = new Singleton;
			}
			_smtx.unlock();
		}

		return *_spInst;
	}

	// һ��û��Ҫ�ͷŶ��󣬽��̽����Ժ���ͷ�
	// ���ǿ����ṩ�����ͷŵĽӿ�
	static void DelInstace()
	{
		_smtx.lock();
		if (_spInst == nullptr)
		{
			delete _spInst;
			_spInst = nullptr;
		}
		_smtx.unlock();
	}

private:
	// ���캯��˽�л�
	Singleton()
	{}

	Singleton(const Singleton&) = delete;

	static Singleton* _spInst;
	static mutex _smtx;
};

//class CGarbo
//{
//public:
//	~CGarbo()
//	{
//		Singleton::DelInstace();
//	}
//};
//
//static CGarbo gc;

Singleton* Singleton::_spInst = nullptr; // main����֮ǰ�ʹ�����ʼ��ָ��
mutex Singleton::_smtx;

// ����
// �ŵ㣺ʵ�ּ��
// ȱ�㣺��main����֮ǰ��ʼ��ʵ������������е����϶࣬������������������������������������ϵ���޷���֤������ʼ��ʵ����˳��

// ����
// �ŵ㣺���ڵ�һ�ε��ó�ʼ������ʵ������Ӱ���������������������ʱ������ʼ����˳����Կ���
// ȱ�㣺ʵ����Ը���

//int main()
//{
//	/*cout << &Singleton::GetInstance() << endl;
//	cout << &Singleton::GetInstance() << endl;
//	cout << &Singleton::GetInstance() << endl;
//	cout << &Singleton::GetInstance() << endl;*/
//
//	// ���߳�������Singleton::GetInstance()����û���̰߳�ȫ�����⣿
//	// 
//	/*vector<thread> vthreads;
//	for (size_t i = 0; i < 4; ++i)
//	{
//	vthreads.push_back(thread([]()
//	{
//	this_thread::sleep_for(std::chrono::seconds(1));
//	for (size_t i = 0; i < 10; ++i)
//	{
//	cout << &Singleton::GetInstance() << endl;
//	}
//	}));
//	}
//
//	for (auto& e : vthreads)
//	{
//	e.join();
//	}*/
//
//	//volatile const int a = 10;
//	/*const int a = 10;
//	int* p = (int*)&a;
//	*p = 20;
//	cout << a << endl;*/
//
//	//char* p = new char[1024 * 1024 * 1024];
//
//	int i = 1;
//	// ��ʽ����ת�� 
//	double d = static_cast<double>(i); // ������ͣ��������-���������Ƶ�����֮���ת��
//	printf("%d, %.2f\n", i, d);
//
//	int* p = &i;
//	// ��ʾ��ǿ������ת��
//	int address = reinterpret_cast<int>(p); // ��������͵�ת��
//
//	volatile const int a = 2;
//	int* p1 = const_cast<int*>(&a);  // ȥ��const���Ե�ת��
//	*p1 = 3;
//	cout << a << endl;
//
//	return 0;
//}

class A
{
public:
	virtual void f() {}

	int _a;
};

class B : public A
{
	int _b;
};

void fun(A* pa)
{
	// dynamic_cast���ȼ���Ƿ���ת���ɹ����ܳɹ���ת���������򷵻�
	B* pb1 = static_cast<B*>(pa);
	B* pb2 = dynamic_cast<B*>(pa);

	cout << "pb1:" << pb1 << endl;
	cout << "pb2:" << pb2 << endl;
}

int main()
{
	//A* pa = new A;
	//B* pb = new B;
	// ��ָ�� = ��ָ��  ���ֱ�Ӿ�֧�ֵ���Ƭ�����Բ���ת��
	//pa = pb;

	// ��ָ�� = ��ָ�� ��������Ҫת������һ��������ת��ʱ�����ʵģ���������²���Ҫ
	// B* p = (B*)pa;  // ������ת��ʱ����ȫ

	// dynamic_cast��������ʶ����ָ����ָ����������������
	//A* pa = new A;
	A* pa = new B;
	B* p = dynamic_cast<B*>(pa); // ����ת���ǰ�ȫ�����pa��ָ��B����(����)�Ķ���ģ��Ϳ��Գɹ�
	cout << p << endl;           //                 ���pa��ָ��A����(����)�Ķ���ģ�ʧ�ܣ�����NULL

	return 0;
}