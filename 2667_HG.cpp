#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;


int arr[25][25];
bool check[25][25];
int components[25 * 25];  // 각 컴포넌트에 몇 개의 노드가 포함되는지 저장
int cnt_component = 0;
int cnt_node = 0;
int n = 0;

void DFS(int i, int j)
{
	check[i][j] = true;

	if (-1 < i + 1 && i + 1 < n && -1 < j  && j < n)                               // 범위 체크
		if (arr[i + 1][j] == 1 && check[i + 1][j] == false)  // 노드가 존재하면서 방문하지 않았을 경우 탐색
			DFS(i + 1, j);
	

	if (-1 < i - 1 && i - 1 < n && -1 < j && j < n)
		if (arr[i - 1][j] == 1 && check[i - 1][j] == false)
			DFS(i - 1, j);

	if (-1 < i && i < n && -1 < j && j + 1 < n)
		if (arr[i][j + 1] == 1 && check[i][j + 1] == false)
			DFS(i, j + 1);

	if (-1 < i && i < n && -1 < j - 1 && j - 1 < n)
		if (arr[i][j - 1] == 1 && check[i][j - 1] == false)
			DFS(i, j - 1);

	cnt_node++;
}


int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			scanf("%1d", &arr[i][j]);
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 1 && check[i][j] == false)
			{
				DFS(i, j);
				components[cnt_component++] = cnt_node;
				
				cnt_node = 0;
			}
		}
	}

	if (cnt_component == 0)  // 하나도 없는 경우
	{
		printf("%d\n", 0);
	}
	else
	{
		sort(components, components + cnt_component);
		printf("%d\n", cnt_component);
		for (int i = 0; i < cnt_component; i++)
			printf("%d\n", components[i]);
	}
}