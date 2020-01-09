#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int N, k, num;
	scanf("%d %d", &N, &k);
	vector<int> v(N);
	for (int i = 0; i < v.size(); i++) {
		scanf("%d", &num);
		v[i] = num;
	}
	stable_sort(v.begin(), v.end());
	printf("%d\n", v[k - 1]);
	return 0;
}