#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int T;
    long long temp; // T : 카드의 갯수
    scanf("%d", &T);
    // int a[10001] ={0,};
    vector<long long> a;
    
    for(int i = 0 ; i < T ; i++){
        scanf("%lld", &temp);
        // a[temp]++;
        a.push_back(temp);
    }

    sort(a.begin(), a.end());

    long long max_num, num;
    int cnt,max_cnt;

    max_num = a[0];
    num = a[0];
    cnt = 1;
    max_cnt = 1;
    
    for(int i = 1 ; i < T ; i++){
        if(num == a[i]){ // 현재 비교중인 num과 지금 a가 같으면 cnt++
            cnt++;
        }else{  //안같으면
            cnt = 1;
            num = a[i];
        }
        if(max_cnt < cnt){  //max값 바꿔주기
                max_cnt = cnt;
                max_num = num;
        }
    }


    // 백준 솔루션
    // for(int i = 1 ; i < T ; i++){
    //     if(a[i-1] == a[i]){ // 전에꺼랑 같으면
    //         cnt++;
    //     }
    //     else{
    //         cnt = 1;
    //     }
    //     if(max_cnt < cnt){
    //         max_num = a[i];
    //         max_cnt = cnt;
    //     }
    // }

    printf("%lld\n", max_num);

    return 0;
}