#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100001

vector<int> G[MAX];
bool check[MAX];
bool cycle_check[MAX];
bool isCycle = false;

void DFS(int node, int start)
{
	check[node] = true;

	int next;
	for (int i = 0; i < G[node].size(); i++)
	{
		next = G[node][i];
		if (check[next] == false)
			DFS(next, start);
		if (next == start)  // 사이클 발견
			isCycle = true;
	}
	if (isCycle)
		cycle_check[node] = true;

}

int main()
{
	int t;
	scanf("%d", &t);

	int n;
	while (t--)
	{
		scanf("%d", &n);

		int u;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &u);
			G[i].push_back(u);
		}

		for (int i = 1; i <= n; i++)
		{
			if (cycle_check[i] == false)
				DFS(i, i);

			// 초기화
			isCycle = false;
			for (int i = 1; i <= n; i++)
				check[i] = false;
		}

		int cnt_noncycle = 0;
		for (int i = 1; i <= n; i++)
		{
			if (cycle_check[i] == false)
				cnt_noncycle++;
		}
		printf("%d\n", cnt_noncycle);

		// 초기화
		for (int i = 1; i <= n; i++)
		{
			G[i].clear();
			check[i] = false;
			cycle_check[i] = false;
		}
	}
}