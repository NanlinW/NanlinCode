int TestAuto()
{
	return 10;
}
int main()
{
	int a = 10;
	auto b = a; //�Ƶ���bΪint
	auto c = 'a'; //�Ƶ���cΪchar
	auto d = TestAuto(); //��TestAuto���ص�����һ������int
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;

	//auto e; �޷�ͨ�����룬ʹ��auto�������ʱ���������г�ʼ��

	return 0;
}
