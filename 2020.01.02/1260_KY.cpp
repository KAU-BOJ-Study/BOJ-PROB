#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
bool check[1001];
vector<int> v[1001];
void dfs(int node) {
	check[node] = true;
	printf("%d ", node);
	for (int i = 0; i < v[node].size(); i++) {
		int x = v[node][i];
		if (check[x] == false) {
			dfs(x);
		}
	}
}
void bfs(int start) {
	queue<int> q;
	memset(check, false, sizeof(check));
	check[start] = true; q.push(start);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		printf("%d ", x);
		for (int i = 0; i < v[x].size(); i++) {
			int y = v[x][i];
			if (check[y] == false) {
				check[y] = true; q.push(y);
			}
		}
	}
}
int main() {
	int N, M, V, m;
	scanf("%d %d %d", &N, &M, &V);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &N, &m);
		v[N].push_back(m); v[m].push_back(N);
		sort(v[N].begin(), v[N].end());
		sort(v[m].begin(), v[m].end());
	}
	dfs(V);
	printf("\n");
	bfs(V);
	return 0;
}