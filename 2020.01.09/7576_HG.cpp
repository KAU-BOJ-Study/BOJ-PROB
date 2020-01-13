#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;
#define MAX 1000

int arr[MAX][MAX];
int dist[MAX][MAX];
int arr_x[4] = { -1, 1, 0, 0 };
int arr_y[4] = { 0, 0, -1, 1 };
int m, n;
queue <pair <int, int> > q;

void BFS(pair <int, int> p)
{
	int x, y, nx, ny;
	x = p.first;
	y = p.second;
	q.pop();

	for (int i = 0; i < 4; i++)
	{
		nx = x + arr_x[i];
		ny = y + arr_y[i];

		if (-1 < nx && nx < n && -1 < ny && ny < m)
			if (arr[nx][ny] == 0 && dist[nx][ny] == -1)  // 토마토가 존재하고 아직 방문하지 않은 노드라면
			{
				q.push(make_pair(nx, ny));
				dist[nx][ny] = dist[x][y] + 1;
			}
	}
}

int main()
{
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &arr[i][j]);
			dist[i][j] = -1;
			if (arr[i][j] == 1)
			{
				q.push(make_pair(i, j));  // 한 시작점에서 BFS를 끝까지 다 하는 것이 아니다. 
				dist[i][j] = 0;                  // 여러개의 시작점에서 각각 한번씩 탐색을 수행해야 하기 때문에 모든 시작점을 먼저 순서대로 큐에 담아야 한다.
			}                                        // 시작점은 0으로 놓아야 +1으로 다음 노드의 최단경로를 0으로 구할 수 있다.
		}
	}

	while (!q.empty())
	{
		BFS(q.front());
	}
	
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (dist[i][j] > ans)
				ans = dist[i][j];
			
			if (arr[i][j] == 0 && dist[i][j] == -1)  // 방문하지 않은 노드가 있다면 -1 출력 후 종료
			{
				printf("%d\n", -1);
				int tt;
				cin >> tt;
				return 0;
			}
		}
	}

	printf("%d\n", ans);
	int tt; 
	cin >> tt;
	return 0;
}