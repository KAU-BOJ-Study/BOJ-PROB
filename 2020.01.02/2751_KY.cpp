#include <stdio.h>
#include <malloc.h>
#include <algorithm>
using namespace std;
int main() {
	int N;
	scanf("%d", &N);
	int* arr = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + N);
	for (int i = 0; i < N; i++) {
		printf("%d\n", arr[i]);
	}
	free(arr);
	return 0;
}
