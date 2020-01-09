#include <iostream>
using namespace std;

int cnt[10001];

int main()
{
	int n;
	scanf("%d", &n);

	int input = 0;
	while (n--)
	{
		scanf("%d", &input);
		cnt[input]++;
	}

	for (int i = 1; i <= 10000; i++)
	{
		while (cnt[i]--)
			printf("%d\n", i);
	}
}