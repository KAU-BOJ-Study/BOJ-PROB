#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

typedef struct user
{
	int age;
	string name;
} user;

bool cmp(const user  &u1, const user &u2)
{
	return u1.age < u2.age;
}

int main()
{
	int n;
	cin >> n;

	vector<user> user_vector(n);
	
	for (int i = 0; i < n; i++)
		cin >> user_vector[i].age >> user_vector[i].name;

	stable_sort(user_vector.begin(), user_vector.end(), cmp);

	for (int i = 0; i < n; i++)
		cout << user_vector[i].age << " " << user_vector[i].name << '\n';
}