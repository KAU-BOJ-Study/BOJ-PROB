#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;
int map[1000][1000];
int check[1000][1000];
int mx[4] = { 0,1,0,-1 };
int my[4] = { 1,0,-1,0 };
int M, N;
int main() {
	queue< pair<int, int> > q;
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			check[i][j] = -1;
			if (map[i][j] == 1) {
				check[i][j] = 0;
				q.push(make_pair(i, j));
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first; int y = q.front().second; q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + mx[i], ny = y + my[i];
			if (0 <= nx && 0 <= ny && nx < N && ny < M) {
				if (check[nx][ny] == -1 && map[nx][ny] != -1) {
					check[nx][ny] = check[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (result < check[i][j]) {
				result = check[i][j];
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (check[i][j] == -1 && map[i][j] == 0) {
				result = -1;
			}
		}
	}
	printf("%d\n", result);
	return 0;
}