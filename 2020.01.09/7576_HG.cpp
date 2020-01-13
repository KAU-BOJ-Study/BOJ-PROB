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
			if (arr[nx][ny] == 0 && dist[nx][ny] == -1)  // �丶�䰡 �����ϰ� ���� �湮���� ���� �����
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
				q.push(make_pair(i, j));  // �� ���������� BFS�� ������ �� �ϴ� ���� �ƴϴ�. 
				dist[i][j] = 0;                  // �������� ���������� ���� �ѹ��� Ž���� �����ؾ� �ϱ� ������ ��� �������� ���� ������� ť�� ��ƾ� �Ѵ�.
			}                                        // �������� 0���� ���ƾ� +1���� ���� ����� �ִܰ�θ� 0���� ���� �� �ִ�.
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
			
			if (arr[i][j] == 0 && dist[i][j] == -1)  // �湮���� ���� ��尡 �ִٸ� -1 ��� �� ����
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