#define _CRT_SECURE_NO_WARNINGS
/*#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <queue>
using namespace std;
int check[25][25];
int arr[25][25];
int ans[25 * 25];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int	N;
void s(int i, int j, int cnt) {
	check[i][j] = true;
	queue< pair<int, int> > q;
	q.push(make_pair(i, j));
	check[i][j] = cnt;
	while (!q.empty()) {
		int x = q.front().first; int y = q.front().second; q.pop(); 
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < N && 0 <= ny && ny < N) {
				if (arr[nx][ny] == 1 && check[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					check[nx][ny] = cnt;
				}
			}
		}
	}
}
int main() {
	int cnt = 0;
	string str;
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++) {
		getline(cin, str);
		for (int j = 0; j<N; j++) {
			arr[i][j] = str[j] - '0';
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (check[i][j] == 0 && arr[i][j] == 1) {
				s(i, j, ++cnt);
			}
		}
	}
	printf("%d\n", cnt);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans[check[i][j]] += 1;
		}
	}
	sort(ans + 1, ans + 1 + cnt);
	for (int i = 1; i <= cnt; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}*/
#include <stdio.h>
#include <algorithm>
using namespace std;

int N, cnt = 0;
int arr[25][25];

void dfs(int x, int y)
{
	int i, xx, yy;
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };
	arr[x][y] = 0;
	cnt++;
	for (i = 0; i < 4; i++)
	{
		xx = x + dx[i];
		yy = y + dy[i];
		if (xx >= 0 && yy >= 0 && xx < N && yy < N && arr[xx][yy] == 1)
		{
			dfs(xx, yy);
		}
	}

}

int main()
{
	int i, j, s = 0;
	int count[316];
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (arr[i][j] == 1) {
				dfs(i, j);
				count[s] = cnt;
				cnt = 0;
				s++;
			}
		}
	}
	sort(count, count + s);
	printf("%d\n", s);
	for (i = 0; i < s; i++)
	{
		printf("%d\n", count[i]);
	}
	return 0;
}