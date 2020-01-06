#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
vector<int> a[1001]; //순열원소의 최대크기는 1000
int check[1001] = {0,};

void dfs(int x){
    check[x] = 1;
    // printf("%d ", x);
    for(int i = 0 ; i < a[x].size(); i++){
        int next = a[x][i];
        // printf("next : %d ", next);
        if(check[next] == 0){
            dfs(next);
        }
    }
}


int main(){
    int T, num, t; //test case : T, 순열 원소 갯수 : num
    scanf("%d", &T);
    for(int i = 0 ; i < T ; i++){
        memset(check,0,sizeof(check));
        scanf("%d", &num);
        for(int j = 1 ; j <= num ; j++){ //그래프로 만들기
            scanf("%d", &t); // j-> t 로의 방향 간선
            a[j].push_back(t); //방향그래프는 한번만 넣어줌
        }

        int cycle = 0 ;

        //탐색하기
        for(int j = 1 ; j <= num ; j++){
            if(check[j] == 0){
                dfs(j);
                cycle++;
            }
        }
        printf("%d\n",cycle);

        for(int j = 1 ; j <= num ; j++){
            a[j].clear();
        }
    }

    return 0;
}