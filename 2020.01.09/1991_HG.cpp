#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// pre-order, in-order, post-order 순으로 출력
int arr[26][2];

void pre_order(int node)
{
	printf("%c", node + 'A');

	if (arr[node][0] != -1)
		pre_order(arr[node][0]);

	if (arr[node][1] != -1)
		pre_order(arr[node][1]);
}

void in_order(int node)
{
	if (arr[node][0] != -1)
		in_order(arr[node][0]);

	printf("%c", node + 'A');

	if (arr[node][1] != -1)
		in_order(arr[node][1]);
}

void post_order(int node)
{
	if (arr[node][0] != -1)
		post_order(arr[node][0]);

	if (arr[node][1] != -1)
		post_order(arr[node][1]);

	printf("%c", node + 'A');
}

int main()
{
	int n;
	scanf("%d", &n);
	getchar();  // 버퍼에 담긴 white space 제거

	char x, y, z;
	// 0~25 = A~Z
	while (n--)
	{
		scanf("%c %c %c", &x, &y, &z);
		getchar();

		if (y == '.')
			arr[x - 'A'][0] = -1;
		else
			arr[x - 'A'][0] = y - 'A';

		if (z == '.')
			arr[x - 'A'][1] = -1;
		else
			arr[x - 'A'][1] = z - 'A';
	}

	pre_order(0);
	printf("\n");

	in_order(0);
	printf("\n");

	post_order(0);
	printf("\n");
}