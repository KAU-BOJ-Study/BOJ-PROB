#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1001

vector<int> G[MAX];
bool check[MAX];

void DFS(int node)
{
	check[node] = true;

	int next;
	for (int i = 0; i < G[node].size(); i++)
	{
		next = G[node][i];
		if (check[next] == false)
			DFS(next);
	}
}


int main()
{
	int cnt_cycle = 0;

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
			if (check[i] == false)
			{
				DFS(i);
				cnt_cycle++;
			}
		}
		printf("%d\n", cnt_cycle);

		// ÃÊ±âÈ­
		cnt_cycle = 0;
		for (int i = 1; i <= n; i++)
		{
			G[i].clear();
			check[i] = false;
		}
	}
}