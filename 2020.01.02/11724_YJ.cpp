#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int check[1001] = {0,};
vector<int> a[1001];
int cnt = 0;

//깊이 우선 탐색
void dfs(int x){
    check[x] = 1; //방문을 표시
    // printf("%d ", x);
    for(int i = 0 ; i < a[x].size() ; i++){
        int next = a[x][i];
        if(check[next]== 0){ //방문 안한 경우
            dfs(next);
        }
    }
}

int main(){
    int n, m; //n <= 1000(정점의 갯수), m간선의 갯수
    scanf("%d %d", &n, &m);

    for(int i = 0 ; i < m ; i++ ){
        int x,y;
        scanf("%d %d", &x, &y);

        a[x].push_back(y);
        a[y].push_back(x); //양방향 그래프
    }
    // for(int i = 1 ; i <= n ; i++){ //정점은 1부터 시작
    //     sort(a[i].begin(), a[i].end());
    // }
    // 연결요소 세는거라 정렬이 필요 없다.

    for(int i = 1 ; i <= n ; i++){
        if(check[i] == 0){
            dfs(i);
            cnt++;
        }
    }
    printf("%d\n", cnt);

    return 0;
}