#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N, result = 0, max = 1, temp = 1;
	long long num;
	cin >> N;
	vector<long long> v(N);
	for (int i = 0; i < N; i++) {
		cin >> num;
		v[i] = num;
	}
	sort(v.begin(), v.end());
	for (int i = 1; i < N; i++) {
		if (v[i] != v[i - 1]) {
			max = 1;
		}
		else {
			max++;
		}
		if (temp < max) {
			temp = max;
			result = i;
		}
	}
	cout << v[result] << '\n';
	return 0;
}