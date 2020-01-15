#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100001

vector<int> T[MAX];
int parent[MAX];
bool check[MAX];

void BFS(int start)
{
	queue<int> q;
	q.push(start);
	check[start] = true;

	while (!q.empty())
	{
		int p = q.front();
		for (int i = 0; i < T[p].size(); i++)
		{
			if (check[T[p][i]] == false)
			{
				check[T[p][i]] = true;
				parent[T[p][i]] = p;
				q.push(T[p][i]);
			}
		}
		q.pop();
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	int loop = n - 1;
	int u, v;
	while (loop--)
	{
		scanf("%d %d", &u, &v);
		T[u].push_back(v);
		T[v].push_back(u);
	}

	parent[0] = 0;
	parent[1] = 0;
	BFS(1);

	for (int i = 2; i <= n; i++)
	{
		printf("%d\n", parent[i]);
	}
}