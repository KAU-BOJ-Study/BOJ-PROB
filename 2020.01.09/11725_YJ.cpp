#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

queue<int> q;
vector<int> v[100001];
int check[100001]; //방문을 체크
int parent[100001]; //부모를 저장
int depth[100001]; // 
int N;

void input(){
    int a, b;
    scanf("%d", &N);
    for(int i = 0; i < N-1 ;i++){
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
}

void bfs(){
    q.push(1); //루트 노드는 1
    parent[1] = 0;
    check[1] = 1; //방문을 체크
    depth[1] = 0; //깊이는 0부터
    // printf("%lu \n", q.size());
    while(!q.empty()){
        int node = q.front(); //현재 방문중인 노드
        q.pop();
        // cout << 1 << endl;
        int node_size = v[node].size();
        for(int i = 0 ; i < node_size ; i++){
            int next = v[node][i];
            if(check[next] == 0){
                check[next] = 1; //방문함
                depth[next] = depth[node] + 1; //깊이는 1개 추가
                parent[next] = node; //부모를 저장
                q.push(next); //큐에 넣기
            }
        }    
    }
}

void printans(){
    for(int i = 2 ; i < N+1 ; i++ ){
        printf("%d\n",parent[i]);
    }
}

int main(){

    input();
    
    bfs();

    printans();

    return 0;
}