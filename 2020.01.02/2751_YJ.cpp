#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int num, t;
    
    scanf("%d", &num);
    vector<int> a;

    for(int i = 0 ; i < num ; i++){
        scanf("%d", &t);
        a.push_back(t);
        //cout << a.size() << '\n';
    }

    sort(a.begin(), a.end());

    for(int i = 0 ; i < num ; i++){
        printf("%d\n", a[i]);
    }

    return 0;
}