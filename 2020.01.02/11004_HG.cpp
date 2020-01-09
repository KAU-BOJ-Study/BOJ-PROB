#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	vector<int> n_vector(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &n_vector[i]);

	sort(n_vector.begin(), n_vector.end());

	printf("%d\n", n_vector[k - 1]);
}