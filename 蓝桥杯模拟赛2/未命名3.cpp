#include <iostream>
#include <cstring>
using namespace std;
int main() {
	int n, m, r, c;
	cin >> n >> m >> r >> c;
	int store[1000][1000];
	// ������Ϊ0
	memset(store, 0, sizeof(store));
	// ����
	int sum = n * m;
	int row = 0, col = 0, cnt = 1;
	store[row][col] = 1;
	while (cnt < sum)
	{
		// �����ߣ�ֱ���ߵ�ͷ������һ���Ѿ��߹�
		while (col + 1 < m && !store[row][col + 1])
			store[row][++col] = ++cnt;
		// �����ߣ�ֱ���ߵ�ͷ������һ���Ѿ��߹�
		while (row + 1 < n && !store[row + 1][col])
			store[++row][col] = ++cnt;
		// �����ߣ�ֱ���ߵ�ͷ������һ���Ѿ��߹�
		while (col - 1 >= 0 && !store[row][col - 1])
			store[row][--col] = ++cnt;
		// �����ߣ�ֱ���ߵ�ͷ������һ���Ѿ��߹�
		while (row - 1 >= 0 && !store[row - 1][col])
			store[--row][col] = ++cnt;
	}
	cout << store[r - 1][c - 1];
	return 0;
}

