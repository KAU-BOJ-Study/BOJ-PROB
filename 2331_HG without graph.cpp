#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;

vector<string> D;

int main()
{
	int a, p;
	scanf("%d %d", &a, &p);
	
	// A ����
	D.push_back(to_string(a));

	int i_input = 0;
	int index = 1;
	vector<string>::iterator iter;
	while (1)
	{
		i_input = 0;
		for (int i = 0; i < D[index - 1].length(); i++)  // ���� string ���̸�ŭ �ݺ�
		{
			i_input += pow(D[index - 1][i] - '0', p);
		}

		iter = find(D.begin(), D.end(), to_string(i_input));
		if (iter == D.end())  // �˻��ؼ� ������ ����
		{
			D.push_back(to_string(i_input));
			index++;
		}
		else
		{
			cout << iter - D.begin() << endl;
			return 0;
		}
	}
}