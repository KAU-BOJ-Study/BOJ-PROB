#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
struct subject
{
	string name;
	int x1, x2, x3;
};
bool cmp(const subject &u1, const subject &u2) {
	if (u1.x1 > u2.x1) {
		return true;
	}
	else if (u1.x1 == u2.x1) {
		if (u1.x2 < u2.x2) {
			return true;
		}
		else if (u1.x2 == u2.x2) {
			if (u1.x3 > u2.x3) {
				return true;
			}
			else if (u1.x3 == u2.x3) {
				if (u1.name < u2.name) {
					return true;
				}
			}
		}
	}
	return false;
}
int main() {
	int N;
	cin >> N;
	vector<subject> sub(N);
	for (int i = 0; i < N; i++) {
		cin >> sub[i].name >> sub[i].x1 >> sub[i].x2 >> sub[i].x3;
	}
	stable_sort(sub.begin(), sub.end(), cmp);
	for (int i = 0; i < N; i++) {
		cout << sub[i].name << '\n';
	}
	return 0;
}