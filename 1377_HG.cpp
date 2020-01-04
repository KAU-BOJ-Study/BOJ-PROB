#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, max = 0;
	scanf("%d", &n);

	vector<pair<int, int>> vec(n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &vec[i].first);
		vec[i].second = i;
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < n; i++)
	{
		if (max < vec[i].second - i)
			max = vec[i].second - i;
	}

	printf("%d\n", max + 1);
}