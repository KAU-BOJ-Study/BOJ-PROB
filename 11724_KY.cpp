#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;
bool check[1001];
vector<int> v[1001];
void dfs(int node) {
	check[node] = true;
	for (int i = 0; i < v[node].size(); i++) {
		int x = v[node][i];
		if (check[x] == false) {
			dfs(x);
		}
	}
}
int main() {
	int N, M, n, m, cnt=0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &n, &m);
		v[n].push_back(m); v[m].push_back(n);
	}
	for (int i = 1; i <= N; i++) {
		if (check[i] == false) {
			dfs(i);
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}