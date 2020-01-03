#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<pair<int, int>> point(n);

	// ���� �켱������ first
	// x, y�Է��� second, first�� �޾� y�� �켱�������� ��´�
	for (int i = 0; i < n; i++)
		cin >> point[i].second >> point[i].first;

	sort(point.begin(), point.end());

	for (int i = 0; i < n; i++)
		cout << point[i].second << " " << point[i].first << '\n';
}