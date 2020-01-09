#include <iostream>
using namespace std;
#define MAX 1000000

int arr[MAX];

void quickSort(int begin, int end, int arr[])
{
	if (begin >= end)
		return;

	int pivotIndex = begin;
	int i = begin + 1;
	int j = end;

	while (i <= j)  // 엇갈리기 전까지 반복
	{
		while (i <= end && arr[i] <= arr[pivotIndex])
			i++;
		while (j > begin && arr[j] >= arr[pivotIndex])
			j--;
		if (i > j)  // 엇갈리면 피봇과 j를 swap. 이제 피봇은 고정
		{
			int temp = arr[j];
			arr[j] = arr[pivotIndex];
			arr[pivotIndex] = temp;
		}
		else // 엇갈리지 않았으면 i와 j를 swap
		{
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	quickSort(begin, j - 1, arr);
	quickSort(j + 1, end, arr);
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	quickSort(0, n - 1, arr);

	for (int i = 0; i < n; i++)
		cout << arr[i] << '\n';
}