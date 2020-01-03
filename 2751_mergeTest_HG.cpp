#include <iostream>
using namespace std;
#define MAX 1000000

int arr[MAX];
int sortedArr[MAX];

// 원소가 1개가 될 때까지 계속 절반으로 나누면 결국 정렬돼있는 상태.
// 여기서 두 배열의 모든 원소 중 가장 작은 원소를 먼저 넣어주면서 merge.
// 의미상 두 배열이라고 표현했을 뿐 사실 하나의 배열 안에서 절반을 나눈 것처럼 인덱스만 따로 기억한 것 뿐

// i는 왼쪽 배열의 첫번째 원소
// j는 오른쪽 배열의 첫번째 원소
// k는 병합된 배열의 첫번째 원소
void merge(int start, int mid, int end, int arr[])
{
	int i = start;
	int j = mid + 1;
	int k = start;

	// 작은 순서대로 sortedArr에 삽입
	// i와 j 둘 중 하나가 끝까지 갈 때 까지 반복
	while (i <= mid && j <= end) 
	{
		if (arr[i] <=arr[j])
			sortedArr[k] = arr[i++];
		else
			sortedArr[k] = arr[j++];

		k++;
	}

	// 혼자 남은 나머지 배열의 모든 값을 넣어준다
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
	// 크기가 1보다 큰 경우에 실행
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