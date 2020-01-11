#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;
#define MAX 100

int arr[MAX][MAX];
int group[MAX][MAX];  // (i, j)가 어느 그룹에 속하는가. 0이면 아직 미방문 or 소속 그룹 없음
int dist[MAX][MAX];

int arr_x[4] = { -1, 1, 0, 0 };
int arr_y[4] = { 0, 0, -1, 1 };

int cnt_components = 0;  // 덩어리의 개수. 
int n;

void BFS(int i, int j)
{
	group[i][j] = ++cnt_components;
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));

	int x, y, nx, ny;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			nx = x + arr_x[i];
			ny = y + arr_y[i];

			if (arr[nx][ny] == 1 && group[nx][ny] == 0
				&& -1 < nx && nx < n
				&& -1 < ny && ny < n)
			{
				q.push(make_pair(nx, ny));
				group[nx][ny] = cnt_components;
			}
		}
	}
}

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 1 && group[i][j] == 0)
				BFS(i, j);
		}
	}

	int ans = -1;
	for (int g = 1; g <= cnt_components; g++)
	{
		queue<pair<int, int>> q;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				dist[i][j] = -1;  // 일단 모든 칸의 거리 -1로 초기화
				if (arr[i][j] == 1 && group[i][j] == g)  // 같은 그룹인 것만 전부 큐에 담는다. 
				{
					dist[i][j] = 0;  // 같은 그룹에 있으면 거리는 0
					q.push(make_pair(i, j));
				}
			}
		}

		int x, y, nx, ny;
		while (!q.empty())
		{
			x = q.front().first;
			y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				nx = x + arr_x[i];
				ny = y + arr_y[i];

				if (dist[nx][ny] == -1  // 같은 그룹이 아닌 곳만 탐색 ( 최단거리를 찾기 위함 )
					&& -1 < nx && nx < n
					&& -1 < ny && ny < n) // 섬이 아닌 곳도 갈 수만 있다면 전부 탐색 ( 다리는 섬이 아닌 곳에 놓기 때문 )
				{
					dist[nx][ny] = dist[x][y] + 1;  // 모든 칸에 대해서 탐색하기 때문에 더 짧은 경로가 있다면 갱신될 것
					q.push(make_pair(nx, ny));
				}
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (arr[i][j] == 1 && group[i][j] != g)  // 다른 그룹의 섬에 대하여
				{
					if (ans == -1 || dist[i][j] - 1 < ans)  // 아직 답이 나오지 않았거나 갱신될 답이 기존 답보다 작을(다리의 길이가 짧을) 경우
					{
						ans = dist[i][j] - 1;  // 섬까지 가는 것이 아니라 섬 바로 이전 칸 까지만 다리를 놓으면 되기 때문에 -1
					}
				}
			}
		}
	}

	printf("%d\n", ans);
}