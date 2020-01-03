#include <stdio.h>
int main() {
	int arr[10001] = { 0 }, N,k;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &k);
		arr[k]++;
	}
	for (int i = 0; i < 10000; i++) {
		for (int j = 0; j < arr[i]; j++) {
			printf("%d\n", i);
		}
	}
	return 0;
}