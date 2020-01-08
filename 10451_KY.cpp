#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;
int check[1001];
vector<int> graph[1001];
int cnt = 0;
void dfs(int i) {
	check[i]++;
	for (int k = 0; k < graph[i].size(); k++) {
		int v = graph[i][k];
		if (check[v] == 0) {
			dfs(v);
		}
		else if (check[v] == 1) {
			cnt++;
		}
	}
}
int main() {
	int K, V, is = true;
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		memset(check, 0, sizeof(check));
		memset(graph, 0, sizeof(graph));
		scanf("%d", &V);
		for (int j = 1; j <= V; j++) {
			int e;
			scanf("%d", &e);
			graph[j].push_back(e);
		}
		for (int i = 1; i <= V; i++) {
			if (check[i] == 0) {
				dfs(i);
			}
		}
		printf("%d\n", cnt);
		cnt = 0;
	}
	return 0;
}