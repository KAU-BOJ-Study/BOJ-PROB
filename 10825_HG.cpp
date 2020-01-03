#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 국어 DESC
// 영어 ASC
// 수학 DESC
// str ASC

typedef struct student
{
	string name;
	int kor;
	int eng;
	int mth;
} student;

bool cmp(const student &s1, const student &s2)
{
	if (s1.kor > s2.kor)
		return true;
	else if (s1.kor == s2.kor)
	{
		if (s1.eng < s2.eng)
			return true;
		else if (s1.eng == s2.eng)
		{
			if (s1.mth > s2.mth)
				return true;
			else if (s1.mth == s2.mth)
			{
				if (s1.name <= s2.name)
					return true;
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

int main()
{
	int n;
	cin >> n;

	vector<student> std_vector(n);
	for (int i = 0; i < n; i++)
	{
		cin >> std_vector[i].name >> std_vector[i].kor 
			>> std_vector[i].eng >> std_vector[i].mth;
	}

	sort(std_vector.begin(), std_vector.end(), cmp);

	for (int i = 0; i < n; i++)
		cout << std_vector[i].name << '\n';
}