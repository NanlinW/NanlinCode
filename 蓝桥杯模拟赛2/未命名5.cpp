//���
//����DFS+����������
//ö�ٳ�����Ϊ n{n}n �Ķ�����01������ i{i}i λ�ϵĶ�����λ�������Ƿ���ֲ����һͳ�Ƴ�����ֲ����������Դ�ά����ֲ��������ֵ���ɡ�
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

/*
6
1 1 2
1 4 2
1 7 2
4 1 2
4 4 2
4 7 2
*/

using namespace std;

const int MAXN = 1000 + 10;
int n;
int x[MAXN], y[MAXN], r[MAXN];
double pi = acos(-1);
bool vis[MAXN];
int ans = 0;

bool cal(int i)
{
	for(int j = 0; j < n; j ++)
	{
		if(i != j && vis[j])
		{
			int dis = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
			if(dis < (r[i] + r[j]) * (r[i] + r[j])) return false;
		}
	}
	return true;
}

void dfs(int step, int sum)
{
	if(step == n)
	{
		ans = max(ans, sum);
		return;
	}
	for(int i = 0; i < n; i ++)
	{
		if(!vis[i])
		{
			int tmp = r[i];
			if(!cal(i)) r[i] = 0;
			vis[i] = true;
			dfs(step + 1, sum + r[i] * r[i]);
			vis[i] = false;
			r[i] = tmp;
		}
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i ++)
		scanf("%d%d%d", &x[i], &y[i], &r[i]);
	dfs(0, 0);
	printf("%d", ans);
	return 0;
}


