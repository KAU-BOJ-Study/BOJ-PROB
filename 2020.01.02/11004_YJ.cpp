#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int T, k; // T : 카드의 갯수
    long long temp; 
    scanf("%d %d", &T, &k);
    // int a[10001] ={0,};
    vector<long long> a;
    
    for(int i = 0 ; i < T ; i++){
        scanf("%lld", &temp);
        // a[temp]++;
        a.push_back(temp);
    }

    sort(a.begin(), a.end());

    printf("%lld\n", a[k-1]);


    return 0;
}