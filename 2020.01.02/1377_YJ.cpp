#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n, temp;
    scanf("%d", &n);
    vector<pair<int, int> > a(n);


    for(int i = 0 ; i < n ; i++){
        scanf("%d", &a[i].first);
        a[i].second = i; //원래의 순서
    }

    sort(a.begin(), a.end()); //오름차순 정렬

    int max = 0, index = 0; //max 필수적으로 초기화 필요!
    // 뒤로 이동하는 것은 무시 (원래의 순서 - 나중의 순서 < 0)
    // 앞으로 이동하는 것 중에 index가 가장 큰 것 (원래의 순서 - 나중 순서 > 0)
    for(int i = 0 ; i < n ; i++){
        //나중의 순서 : i , 원래의 순서 : a[i].second
        index = a[i].second - i;
        if(max < index){
            max = index;
        }
    }

    printf("%d\n", max+1);
    //마지막 단계에서 하나도 움직이지 않은 경우도 한 단계임

    return 0;
}