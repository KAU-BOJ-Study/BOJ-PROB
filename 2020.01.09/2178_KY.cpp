#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;
int map[100][100];
int check[100][100];
int mx[4] = { 0,1,0,-1 };
int my[4] = { 1,0,-1,0 };
int w, h;
void land(int i, int j) {
	int cnt = 0;
	queue< pair<int,int> > q;
	q.push(make_pair(i, j));
	check[i][j] = 1;
	while (!q.empty()) {
		int x = q.front().first; int y = q.front().second; q.pop(); 
		cnt = check[x][y];
		for (int i = 0; i < 4; i++) {
			int nx = x + mx[i], ny = y + my[i];
			if (0 <= nx && 0 <= ny && nx < h && ny < w) {
				if (check[nx][ny] == 0 && map[nx][ny] == 1) {
					check[nx][ny] = cnt + 1;
					q.push(make_pair(nx, ny)); 
				}
			}
		}
	}
}
int main() {
	scanf("%d %d", &h, &w);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (check[i][j] == 0 && map[i][j] == 1) {
				land(i, j);
			}
		}
	}
	printf("%d\n", check[h-1][w-1]);
	return 0;
}