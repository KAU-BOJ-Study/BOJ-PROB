#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 100001

vector<pair<int, int>> T[MAX];  // ����� ��� ��ȣ, ����ġ
bool check[MAX];
int dist[MAX];

/*
������ ��忡�� ��� ��� Ž��
Ž�� ��� ���� �� ��θ� ���� ��� A
A���� �ٽ� �� �� ��� ��� Ž��
���� �� ��ΰ� Ʈ���� ����
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
				dist[next] = dist[p] + T[p][i].second;  // ��庰�� ����ġ�� ��� ���Ѵ�
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
	int root; // �ι�° Ž���� ��Ʈ
	root = max_element(dist + 1, dist + v + 1) - dist;  // [1] ~ [v] ���̿��� ������ ã�´�
	
	for (int i = 1; i <= v; i++)
	{
		dist[i] = 0;
		check[i] = false;
	}
	
	BFS(root);

	printf("%d\n", *max_element(dist + 1, dist + v + 1));
}