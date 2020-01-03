#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 100000

int main()
{
	int n;
	cin >> n;

	vector<pair<int, int>> point(n);

	for (int i = 0; i < n; i++)
		cin >> point[i].first >> point[i].second;

	sort(point.begin(), point.end());

	for (int i = 0; i < n; i++)
		cout << point[i].first << " " << point[i].second << '\n';
}