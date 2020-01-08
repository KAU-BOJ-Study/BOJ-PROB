#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;
int check[20001];
vector<int> graph[20001];
void dfs(int i, int num) {
	check[i] = num;
	for (int k = 0; k < graph[i].size(); k++) {
		int v = graph[i][k];
		if (check[v] == 0) {
			dfs(v, 3 - num);
		}
	}
}
int main() {
	int K, V, E, is = true;
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		memset(check, 0, sizeof(check));
		memset(graph, 0, sizeof(graph));
		scanf("%d %d", &V, &E);
		for (int j = 0; j < E; j++) {
			int v, e;
			scanf("%d %d", &v, &e);
			graph[v].push_back(e);
			graph[e].push_back(v);
		}
		for (int i = 1; i <= V; i++) {
			if (check[i] == 0) {
				dfs(i, 1);
			}
		}
		for (int i = 1; i <= V; i++) {
			for (int j = 0; j < graph[i].size(); j++) {
				int k = graph[i][j];
				if (check[i] == check[k]) {
					is = false;
				}
			}
		}
		if (is) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
			is = true;
		}

	}
	return 0;
}