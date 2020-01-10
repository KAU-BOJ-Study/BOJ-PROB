#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#define MAX 50

int arr[MAX][MAX];
bool check[MAX][MAX];
int cnt_components = 0;

int w, h;

void DFS(int i, int j)
{
	check[i][j] = true;

	// 상
	if (arr[i - 1][j] == 1 && check[i - 1][j] == false
		&& -1 < i - 1 && i - 1 < h 
		&& -1 < j && j < w)
	{
		DFS(i - 1, j);
	}

	// 하
	if (arr[i + 1][j] == 1 && check[i + 1][j] == false 
		&& -1 < i + 1 && i + 1 < h 
		&& -1 < j && j < w)
	{
		DFS(i + 1, j);
	}

	// 좌
	if (arr[i][j - 1] == 1 && check[i][j - 1] == false 
		&& -1 < i && i < h 
		&& -1 < j - 1 && j - 1 < w)
	{
		DFS(i, j - 1);
	}
	 
	// 우
	if (arr[i][j + 1] == 1 && check[i][j + 1] == false
		&& -1 < i && i < h
		&& -1 < j + 1 && j + 1 < w)
	{
		DFS(i, j + 1);
	}

	// 우상
	if (arr[i - 1][j + 1] == 1 && check[i - 1][j + 1] == false
		&& -1 < i - 1 && i - 1 < h
		&& -1 < j + 1 && j + 1 < w)
	{
		DFS(i - 1, j + 1);
	}

	// 좌상
	if (arr[i - 1][j - 1] == 1 && check[i - 1][j - 1] == false
		&& -1 < i - 1 && i - 1 < h
		&& -1 < j - 1 && j - 1 < w)
	{
		DFS(i - 1, j - 1);
	}

	// 좌하
	if (arr[i + 1][j -1] == 1 && check[i + 1][j - 1] == false 
		&& -1 < i + 1 && i + 1 < h 
		&& -1 < j - 1 && j - 1 < w)
	{
		DFS(i + 1, j - 1);
	}

	// 우하
	if (arr[i + 1][j + 1] == 1 && check[i + 1][j + 1] == false
		&& -1 < i + 1 && i + 1 < h
		&& -1 < j + 1 && j + 1 < w)
	{
		DFS(i + 1, j + 1);
	}
}

int main()
{
	while (1)
	{
		scanf("%d %d", &w, &h);
		if (w == 0 || h == 0)  // 0 0 입력 시 종료
			break;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				scanf("%1d", &arr[i][j]);
			}
		}

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (arr[i][j] == 1 && check[i][j] == false)
				{
					DFS(i, j);
					cnt_components++;
				}
			}
		}


		printf("%d\n", cnt_components);
		cnt_components = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				arr[i][j] = 0;
				check[i][j] = false;
			}
		}
	}
}