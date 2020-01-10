#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;
#define MAX 100

int arr[MAX][MAX];
bool check[MAX][MAX];
int dist[MAX][MAX];  // 시작점부터 (i, j)까지의 거리 저장
int n, m;

// x, y -> 상하좌우 좌표
int x_arr[4] = {-1, 1, 0, 0};
int y_arr[4] = {0, 0, -1, 1};

void BFS(int i, int j)
{
	queue<pair<int, int>> q;
	check[i][j] = true;
	dist[i][j] = 1;

	q.push(make_pair(i, j));
	
	int x, y, nx, ny;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			nx = x + x_arr[i];
			ny = y + y_arr[i];

			if (arr[nx][ny] == 1 && check[nx][ny] == false
				&& -1 < nx && nx < n
				&& -1 < ny && ny < m)
			{
				check[nx][ny] = true;
				dist[nx][ny] = dist[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}

}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}

	BFS(0, 0);
	printf("%d\n", dist[n - 1][m - 1]);
}