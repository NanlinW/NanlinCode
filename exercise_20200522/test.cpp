void TestFor()
{
	int array[] = { 1, 2, 3, 4, 5 };
	for (auto e : array)//�����������޸�
		e *= 2;

	for (auto& e : array)//����+�޸�
		e *= 2;

	for (const auto& e : array)//����+ֻ��
		e *= 2;

	for (auto e : array)
		cout << e << " ";
	return 0;
}
