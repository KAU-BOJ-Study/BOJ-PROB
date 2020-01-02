//11650 STL sort pair 사용
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int num;
    
    scanf("%d", &num);
    vector<pair<int, int> > v(num);

    for(int i = 0 ; i < num ; i++){
        scanf("%d %d", &v[i].first, &v[i].second);
    }

    sort(v.begin(), v.end());

    for(int i = 0 ; i < num ; i++){
        printf("%d %d\n", v[i].first, v[i].second);
    }

    return 0;
}