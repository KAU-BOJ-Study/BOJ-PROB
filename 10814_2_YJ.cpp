//stable sort 사용 =>  코드길이 짧고, 시간 조금 덜 걸림

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b){
    return a.first < b.first; //age만 비교해도 가능
}

int main(){
    int T;
    scanf("%d", &T);
    vector<pair<int, string> > a(T);  //age, name을 pair로 사용
    for(int i = 0 ; i < T ; i++){
        cin >> a[i].first >> a[i].second;
    }

    stable_sort(a.begin(), a.end(), cmp);

    for(int i  = 0 ; i < T ; i++){
        printf("%d %s\n", a[i].first, a[i].second.c_str());
        //c_str() : string -> char * 로 변환하는 함수
    }
    return 0;
}