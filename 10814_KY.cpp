#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
struct user
{
	int age;
	string name;
};
bool cmp(const user& u1, const user& u2) {
	if (u1.age < u2.age) {
		return true;
	}
	return false;
}
int main() {
	int N;
	cin >> N;
	vector<user> u(N);
	for (int i = 0; i < N; i++) {
		cin >> u[i].age >> u[i].name;
	}
	stable_sort(u.begin(), u.end(), cmp);
	for (int i = 0; i < N; i++) {
		cout << u[i].age << ' ' << u[i].name << '\n';
	}
	return 0;
}