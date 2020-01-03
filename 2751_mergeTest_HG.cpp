#include <iostream>
using namespace std;
#define MAX 1000000

int arr[MAX];
int sortedArr[MAX];

// ���Ұ� 1���� �� ������ ��� �������� ������ �ᱹ ���ĵ��ִ� ����.
// ���⼭ �� �迭�� ��� ���� �� ���� ���� ���Ҹ� ���� �־��ָ鼭 merge.
// �ǹ̻� �� �迭�̶�� ǥ������ �� ��� �ϳ��� �迭 �ȿ��� ������ ���� ��ó�� �ε����� ���� ����� �� ��

// i�� ���� �迭�� ù��° ����
// j�� ������ �迭�� ù��° ����
// k�� ���յ� �迭�� ù��° ����
void merge(int start, int mid, int end, int arr[])
{
	int i = start;
	int j = mid + 1;
	int k = start;

	// ���� ������� sortedArr�� ����
	// i�� j �� �� �ϳ��� ������ �� �� ���� �ݺ�
	while (i <= mid && j <= end) 
	{
		if (arr[i] <=arr[j])
			sortedArr[k] = arr[i++];
		else
			sortedArr[k] = arr[j++];

		k++;
	}

	// ȥ�� ���� ������ �迭�� ��� ���� �־��ش�
	if (i > mid)
	{
		for (int index = j; index <= end; index++)
			sortedArr[k++] = arr[index];
	}
	else
	{
		for (int index = i; index <= mid; index++)
			sortedArr[k++] = arr[index];
	}

	for (int i = start; i <= end; i++)
		arr[i] = sortedArr[i];
}

void mergeSort(int start, int end, int arr[])
{
	// ũ�Ⱑ 1���� ū ��쿡 ����
	if (start < end)
	{
		int mid = (start + end) / 2;
		mergeSort(start, mid, arr);
		mergeSort(mid + 1, end, arr);

		merge(start, mid, end, arr);
	}
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	mergeSort(0, n - 1, arr);

	for (int i = 0; i < n; i++)
		cout << arr[i] << '\n';

	int tt;
	cin >> tt;
}