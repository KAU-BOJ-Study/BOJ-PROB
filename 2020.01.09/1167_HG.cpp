#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 100001

vector<pair<int, int>> T[MAX];  // 연결된 노드 번호, 가중치
bool check[MAX];
int dist[MAX];

/*
임의의 노드에서 모든 노드 탐색
탐색 결과 가장 먼 경로를 갖는 노드 A
A에서 다시 한 번 모든 노드 탐색
가장 긴 경로가 트리의 지름
*/

void BFS(int start)
{
	queue<int> q;
	q.push(start);
	check[start] = true;
	dist[start] = 0;

	while (!q.empty())
	{
		int p = q.front();
		for (int i = 0; i < T[p].size(); i++)
		{
			int next = T[p][i].first;
			if (check[next] == false)
			{
				check[next] = true;
				dist[next] = dist[p] + T[p][i].second;  // 노드별로 가중치를 모두 구한다
				q.push(next);
			}
		}
		q.pop();
	}
}

int main()
{
	int v;
	scanf("%d", &v);

	for (int i = 0; i < v; i++)
	{
		int node = 0;
		scanf("%d", &node);

		int n, l;  // node, length
		while (1)
		{
			scanf("%d", &n);
			if (n == -1)
				break;
			scanf("%d", &l);
			T[node].push_back(make_pair(n, l));
		}
	}

	BFS(1);
	int root; // 두번째 탐색의 루트
	root = max_element(dist + 1, dist + v + 1) - dist;  // [1] ~ [v] 사이에서 최장경로 찾는다
	
	for (int i = 1; i <= v; i++)
	{
		dist[i] = 0;
		check[i] = false;
	}
	
	BFS(root);

	printf("%d\n", *max_element(dist + 1, dist + v + 1));
}