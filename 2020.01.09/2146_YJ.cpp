#include <iostream>
#include <stdio.h>
#include <queue>
#define MIN(a,b) ((a<b)? a:b)

using namespace std;

int m[100][100]; //지도
int d[100][100]; //거리
int ch[100][100]; //마지막에 거리구할때 체크

int ax[] = {-1,1, 0, 0};
int ay[] = {0,0, 1, -1};

int r; //지도의 한 변의 길이

void input(){
    scanf("%d", &r);
    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < r ; j++){
            scanf("%d", &m[i][j]);
            d[i][j] = -1;
        }
    }
}

queue<pair<int, int> > q; //그룹만드는 q
queue<pair<int, int> > qd; //거리, 땅 넓히는 q

void grb(){
    int g = 0; //그룹은 1부터 시작
    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < r ; j++){
            if(m[i][j]==1 && d[i][j] == -1){ //땅이 있고, 아직 거리에 추가하지 않음
                m[i][j] = ++g; //그룹을 만들어주고
                d[i][j] = 0; //거리는 0으로 만들어준다.
                q.push(make_pair(i,j));
                qd.push(make_pair(i,j));
                
            }
            while(!q.empty()){
                // cout << i << " " << j << endl;
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int  k = 0 ; k < 4 ; k++){
                    int nx = x+ ax[k];
                    int ny = y + ay[k];
                    if(nx >= 0 && nx < r && ny >= 0 && ny < r){
                        // cout << nx << "," << ny << endl;
                        if(m[nx][ny] == 1 && d[nx][ny] == -1){
                        m[nx][ny] = g; //그룹만들기
                        d[nx][ny] = 0; //거리는 0
                        q.push(make_pair(nx,ny));
                        qd.push(make_pair(nx,ny));
                        }
                    }
                }
            }
        }
    }
}
/* 그룹 결과
1 1 1 0 0 0 0 2 2 2 
1 1 1 1 0 0 0 0 2 2 
1 0 1 1 0 0 0 0 2 2 
0 0 1 1 1 0 0 0 0 2 
0 0 0 1 0 0 0 0 0 2 
0 0 0 0 0 0 0 0 0 2 
0 0 0 0 0 0 0 0 0 0 
0 0 0 0 3 3 0 0 0 0 
0 0 0 0 3 3 3 0 0 0 
0 0 0 0 0 0 0 0 0 0

거리 결과
0 0 0 -1 -1 -1 -1 0 0 0 
0 0 0 0 -1 -1 -1 -1 0 0 
0 -1 0 0 -1 -1 -1 -1 0 0 
-1 -1 0 0 0 -1 -1 -1 -1 0 
-1 -1 -1 0 -1 -1 -1 -1 -1 0 
-1 -1 -1 -1 -1 -1 -1 -1 -1 0 
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
-1 -1 -1 -1 0 0 -1 -1 -1 -1 
-1 -1 -1 -1 0 0 0 -1 -1 -1 
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
*/


void bfs(){
    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < r ; j++){
            while(!qd.empty()){
                int x = qd.front().first;
                int y = qd.front().second;
                qd.pop();
                for(int k = 0 ; k < 4 ; k++){
                    int nx = x+ax[k];
                    int ny = y+ay[k];
                    if(nx >= 0 && nx < r && ny < r && ny >= 0){ //좌표값이 범위 안에 있으면
                        if(d[nx][ny] == -1 && m[nx][ny] == 0){ //아직 거리가 없으면
                            d[nx][ny] = d[x][y] + 1;
                            m[nx][ny] = m[x][y];
                            qd.push(make_pair(nx,ny));
                        }
                    }
                }
            }
        }
    }
}
int ans = 1000000;
int cal_dist(){
    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < r ; j++){
            for(int k = 0 ; k < 4 ; k++){
                int nx = i+ax[k];
                int ny = j+ay[k];
                if(nx >= 0 && nx < r && ny < r && ny >= 0){
                    if(m[i][j] != m[nx][ny]){
                        ans = MIN(d[i][j] + d[nx][ny], ans);
                    }
                }
            }
            
        }
    }
    return ans;
}

void printarr(){
    cout << endl;
    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < r ; j++){
            printf("%d ", m[i][j]);
        }
        cout << endl;
    }

    cout << endl;
    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < r ; j++){
            printf("%d ", d[i][j]);
        }
        cout << endl;
    }
}

int main(){
    input();
    grb();
    bfs();
    // printarr();

    cout << cal_dist() << '\n';

}