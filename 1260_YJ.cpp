#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>  //memset

using namespace std;

vector<int> a[1001]; //인접리스트

int check[1001] = {0,};

//깊이 우선 탐색 -> 스택을 이용
void dfs(int x){
    check[x] = 1; //방문 했음
    printf("%d ", x);
    for(int i = 0 ; i < a[x].size() ; i++){
        int next = a[x][i]; //다음 간선
        if(check[next] == 0){ // 방문을 하지 않았으면
            dfs(next);
        }
    }
}

//너비 우선 탐색 -> 큐를 사용
void bfs(int x){
    queue<int> q;
    memset(check, 0, sizeof(check));
    check[x] = 1;
    q.push(x);
    
    while(!q.empty()){
        int node = q.front();
        printf("%d ", node);
        q.pop();

        for(int i = 0 ; i < a[node].size() ; i++){
            int val = a[node][i];

            if(check[val] == 0){ //방문 안한것만 넣기
                check[val] = 1;
                q.push(val);
            }
            
        }

    }
    
}


int main(){
    int V, E, start;
    int x, y;
    scanf("%d %d %d", &V, &E, &start);
    

    for(int i = 0 ; i < E ; i++){
        scanf("%d %d", &x, &y); //x->y로 가는 간선
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(int i = 0 ; i < V ; i++){
        sort(a[i].begin(), a[i].end());
    }

    dfs(start);
    printf("\n");
    bfs(start);
    printf("\n");

    return 0;
}