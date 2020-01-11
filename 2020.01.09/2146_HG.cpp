#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;
#define MAX 100

int arr[MAX][MAX];
int group[MAX][MAX];  // (i, j)�� ��� �׷쿡 ���ϴ°�. 0�̸� ���� �̹湮 or �Ҽ� �׷� ����
int dist[MAX][MAX];

int arr_x[4] = { -1, 1, 0, 0 };
int arr_y[4] = { 0, 0, -1, 1 };

int cnt_components = 0;  // ����� ����. 
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
				dist[i][j] = -1;  // �ϴ� ��� ĭ�� �Ÿ� -1�� �ʱ�ȭ
				if (arr[i][j] == 1 && group[i][j] == g)  // ���� �׷��� �͸� ���� ť�� ��´�. 
				{
					dist[i][j] = 0;  // ���� �׷쿡 ������ �Ÿ��� 0
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

				if (dist[nx][ny] == -1  // ���� �׷��� �ƴ� ���� Ž�� ( �ִܰŸ��� ã�� ���� )
					&& -1 < nx && nx < n
					&& -1 < ny && ny < n) // ���� �ƴ� ���� �� ���� �ִٸ� ���� Ž�� ( �ٸ��� ���� �ƴ� ���� ���� ���� )
				{
					dist[nx][ny] = dist[x][y] + 1;  // ��� ĭ�� ���ؼ� Ž���ϱ� ������ �� ª�� ��ΰ� �ִٸ� ���ŵ� ��
					q.push(make_pair(nx, ny));
				}
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (arr[i][j] == 1 && group[i][j] != g)  // �ٸ� �׷��� ���� ���Ͽ�
				{
					if (ans == -1 || dist[i][j] - 1 < ans)  // ���� ���� ������ �ʾҰų� ���ŵ� ���� ���� �亸�� ����(�ٸ��� ���̰� ª��) ���
					{
						ans = dist[i][j] - 1;  // ������ ���� ���� �ƴ϶� �� �ٷ� ���� ĭ ������ �ٸ��� ������ �Ǳ� ������ -1
					}
				}
			}
		}
	}

	printf("%d\n", ans);
}