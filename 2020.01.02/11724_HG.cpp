#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1001

vector<int> G[MAX];
bool check[MAX];

void DFS(int start)
{
	check[start] = true;

	int next;
	for (int i = 0; i < G[start].size(); i++)
	{
		next = G[start][i];
		if (check[next] == false)
			DFS(next);
	}
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int u, v;
	while (m--)
	{
		scanf("%d %d", &u, &v);

		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	for (int i = 0; i < n; i++)
		sort(G[i].begin(), G[i].end());

	int component = 0;
	for (int i = 1; i <= n; i++)
	{
		if (check[i] == false)
		{
			DFS(i);
			component++;
		}
	}

	printf("%d\n", component);
}