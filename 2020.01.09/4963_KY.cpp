#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;
int map[50][50];
int check[50][50];
int mx[8] = { 0,1,1,1,0,-1,-1,-1 };
int my[8] = { 1,1,0,-1,-1,-1,0,1 };
int w, h;
void land(int i, int j, int cnt) {
	queue< pair<int,int> > q;
	q.push(make_pair(i, j));
	check[i][j] = cnt;
	while (!q.empty()) {
		int x = q.front().first; int y = q.front().second; q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + mx[i], ny = y + my[i];
			if (0 <= nx && 0 <= ny && nx < h && ny < w) {
				if (check[nx][ny] == 0 && map[nx][ny] == 1) {
					check[nx][ny] = cnt;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}
int main() {
	int cnt = 0;
	while (1) {
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0) {
			break;
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%1d", &map[i][j]);
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (check[i][j] == 0 && map[i][j] == 1) {
					land(i, j, ++cnt);
				}
			}
		}
		printf("%d\n", cnt);
		memset(map, 0, sizeof(map));
		memset(check, 0, sizeof(check));
		cnt = 0;
	}
	return 0;
}