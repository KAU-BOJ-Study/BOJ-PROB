#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N, num, result=0, temp;
	scanf("%d", &N);
	vector< pair<int, int> > v(N+1);
	for (int i = 1; i < N+1; i++) {
		scanf("%d", &num);
		v[i].first = num;
		v[i].second = i;
	}
	sort(v.begin(), v.end());
	for (int i = 1; i < N; i++) {
		if (v[i].second > i) {
			temp = v[i].second - i;
			if (temp > result) {
				result = temp;
			}
		}
	}
	printf("%d\n", result + 1);
	return 0;
}
