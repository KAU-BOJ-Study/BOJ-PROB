#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	long long input;
	int cnt = 1, maxCnt = 1, maxIndex = 0;
	scanf("%d", &n);

	vector<long long> n_vector;
	while (n--)
	{
		scanf("%lld", &input);
		n_vector.push_back(input);
	}
	
	sort(n_vector.begin(), n_vector.end());

	for (int i = 1; i < n_vector.size(); i++)
	{
		if (n_vector[i] == n_vector[i - 1])  // 이전 원소랑 같으면 증가
			cnt++;
		else
			cnt = 1;

		if (cnt > maxCnt)
		{
			maxCnt = cnt;
			maxIndex = i;
		}
		
	}
	printf("%lld", n_vector[maxIndex]);
}