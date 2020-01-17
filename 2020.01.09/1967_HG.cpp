#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 10001

vector<pair<int, int>> T[MAX];  // pair = 연결된 노드, 가중치
bool check[MAX];
int dist[MAX];

void BFS(int start)
{
	check[start] = true;
	dist[start] = 0;
	queue<int> q;
	q.push(start);

	while (!q.empty())
	{
		int p = q.front();  // parent
		for (int i = 0; i < T[p].size(); i++)
		{
			int c = T[p][i].first;  // children
			if (check[c] == false)
			{
				q.push(c);
				check[c] = true;
				dist[c] = dist[p] + T[p][i].second;
			}
		}
		q.pop();
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	int u, v, w;
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d %d %d", &u, &v, &w);

		T[u].push_back(make_pair(v, w));
		T[v].push_back(make_pair(u, w));
	}
	BFS(1);

	int root = max_element(dist + 1, dist + 1 + v) - dist;
	for (int i = 1; i <= n; i++)
	{
		check[i] = false;
		dist[i] = 0;
	}
	BFS(root);

	int ans = *max_element(dist + 1, dist + 1 + v);
	printf("%d\n", ans);
}