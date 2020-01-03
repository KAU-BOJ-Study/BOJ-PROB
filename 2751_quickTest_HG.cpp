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

	while (i <= j)  // �������� ������ �ݺ�
	{
		while (i <= end && arr[i] <= arr[pivotIndex])
			i++;
		while (j > begin && arr[j] >= arr[pivotIndex])
			j--;
		if (i > j)  // �������� �Ǻ��� j�� swap. ���� �Ǻ��� ����
		{
			int temp = arr[j];
			arr[j] = arr[pivotIndex];
			arr[pivotIndex] = temp;
		}
		else // �������� �ʾ����� i�� j�� swap
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