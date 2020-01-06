#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100001

pair<int, int> G[MAX];    // <int, int> = <������ ���, cnt_dfs>  cnt_dfs = 0�̸� ���� �湮���� ���� ��
int cnt_dfs = 1;  
bool isCycle = false;
int cnt_cycle = 0;
int cycle_point = 0;

void DFS(int node)
{
	G[node].second = cnt_dfs;

	int next = G[node].first;
	if (G[next].second == 0)  
		DFS(next);
	else if (G[next].second == cnt_dfs)   // next�� �̹� DFS���� �̹� �湮�ߴ� ���. ����Ŭ �߻�!  
	{
		cycle_point = next;  
		isCycle = true;
	}

	if (isCycle)
		cnt_cycle++;

	if (node == cycle_point)  // ����Ŭ ������ ����, ����Ŭ ����
		isCycle = false; 
}

int main()
{
	int t;
	scanf("%d", &t);

	int n;
	while (t--)
	{
		scanf("%d", &n);

		for (int i = 1; i <= n; i++)
			scanf("%d", &G[i]);

		for (int i = 1; i <= n; i++)
		{
			if (G[i].second == 0)
			{
				DFS(i);
				cnt_dfs++;
			}
		}
		printf("%d\n", n - cnt_cycle);

		// �ʱ�ȭ
		cnt_dfs = 1;
		cnt_cycle = 0;
		cycle_point = 0;
		for (int i = 1; i <= n; i++)
		{
			G[i].first = 0;
			G[i].second = 0;
		}
	}
}