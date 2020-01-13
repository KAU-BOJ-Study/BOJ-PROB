#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>
#include <cstring>

#define MIN(a,b) ((a<b) ? a : b)
#define MAX(a,b) ((a>b) ? a : b)

using namespace std;

int M, N; //가로, 세로
vector<int> v[1001]; // 입력받을 토마토
int ans[1001][1001]; //거리를 계산
int ax[] = {1,-1,0,0}; //하 상 우 좌
int ay[] = {0,0,1,-1};
queue<pair<int, int> > q; //bfs를 위한 큐

void input(){
    int temp;
    scanf("%d %d", &M, &N); //가로세로
    for(int i = 0 ; i  < N ; i++){
        for(int j = 0 ; j < M ; j++){
            scanf("%d", &temp);
            v[i].push_back(temp); //토마토 입력받음
            ans[i][j] = -1; //처음에는 방문안함을 표시 (0은 시작점이므로 -1로 시작)
            if(temp == 1){
                q.push(make_pair(i,j)); //입력 받을 때, 익은 토마토는 큐에 넣음
                //BFS는 한 단계씩 진행 된다는 것을 이용하기 위함
                ans[i][j] = 0; //익은 토마토는 익은 토마토와의 거리가 0이다.
            }
        }
    }
}

//1: 익은 토마토 , 0: 익지 않은 토마토, -1: 토마토가 없는 곳
void bfs(){
    while(!q.empty()){
        pair<int, int> point = q.front();
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int nx = point.first+ax[i];
            int ny = point.second+ay[i]; //다음 좌표
            if(nx >= 0 && nx < N && ny>= 0 && ny < M){ //범위 내의 좌표일때,
                // if(v[nx][ny] == -1) ans[nx][ny] = 0;
                if(v[nx][ny] == 0){ //토마토가 안익었으면 
                    v[nx][ny] = 1; //익은 토마토가 됨
                    q.push(make_pair(nx,ny)); //큐에 넣음
                    ans[nx][ny] = ans[point.first][point.second]+1; //거리는 이전거리+1
                } 
            }
        }
    }
}

void printarr(){ //배열 프린트
    cout << endl;
    cout << "ans\n";
    for(int i = 0 ; i  < N ; i++){
        for(int j = 0 ; j < M ; j++){
            printf("%d ", ans[i][j]);
        }
        cout << endl;
    }
}

int output(){
    int max = 0;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            if(ans[i][j] == -1 && v[i][j] == 0) return -1; //방문 안하고 안익은 토마토가 있으면 안됨
            max = MAX(max , ans[i][j]); //최대값이 정답이 됨.
        }
    }
    return max;
}

int main(){

    input();

    bfs();

    // printarr();

    cout << output() << endl;

    return 0;
}