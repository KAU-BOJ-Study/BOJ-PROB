#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>	
using namespace std;
#define MAX 1000

void DFS(vector<int> G[], int start, bool check[])
{
	check[start] = true;
	printf("%d ", start);

	int next;
	for (int i = 0; i < G[start].size(); i++)
	{
		next = G[start][i];
		if (check[next] == false)
			DFS(G, next, check);
	}
}

void BFS(vector <int> G[], int start, bool check[])
{
	queue<int> Q;
	Q.push(start);
	check[start] = true;

	int x, y;
	while (!Q.empty())
	{
		x = Q.front();
		printf("%d ", x);
		Q.pop();
		for (int i = 0; i < G[x].size(); i++)
		{
			y = G[x][i];
			if (check[y] == false)
			{
				check[y] = true;
				Q.push(y);
			}
		}
	}
}

vector<int> G[MAX];
bool check[MAX];

int main()
{
	int n, m, start;
	scanf("%d %d %d", &n, &m, &start);

	int u, v;
	while (m--)
	{
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	for (int i = 0; i < n; i++)
		sort(G[i].begin(), G[i].end());

	DFS(G, start, check);
	printf("\n");

	for (int i = 1; i <= n; i++)
		check[i] = false;

	BFS(G, start, check);
	printf("\n");
}