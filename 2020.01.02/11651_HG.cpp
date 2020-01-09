#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<pair<int, int>> point(n);

	// 정렬 우선기준은 first
	// x, y입력을 second, first로 받아 y를 우선기준으로 잡는다
	for (int i = 0; i < n; i++)
		cin >> point[i].second >> point[i].first;

	sort(point.begin(), point.end());

	for (int i = 0; i < n; i++)
		cout << point[i].second << " " << point[i].first << '\n';
}