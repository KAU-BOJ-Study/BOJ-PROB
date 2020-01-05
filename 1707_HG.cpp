#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 20001

vector<int> G[MAX];
int check[MAX];  // 0 - UNVISITED, 1 - RED, 2 - BLUE

void DFS(int node, int c)
{
	check[node] = c;

	int next;
	for (int i = 0; i < G[node].size(); i++)
	{
		next = G[node][i];
		if (check[next] == 0)
			DFS(next, 3 - c);
	}
}

int main()
{
	int k;
	scanf("%d", &k);

	int n, m;
	while (k--)
	{
		scanf("%d %d", &n, &m);

		int u, v;
		while (m--)
		{
			scanf("%d %d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for (int i = 1; i <= n; i++)
			sort(G[i].begin(), G[i].end());

		for (int i = 1; i <= n; i++)
		{
			if (check[i] == 0)
				DFS(i, 1);
		}

		bool result = true;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < G[i].size(); j++)
			{
				if (check[i] == check[G[i][j]])
					result = false;
			}
		}
		printf("%s\n", result ? "YES" : "NO");

		// 다음 테스트 케이스 위하여 초기화
		result = true;
		for (int i = 1; i <= n; i++)
		{
			G[i].clear();
			check[i] = 0;
		}
	}
}