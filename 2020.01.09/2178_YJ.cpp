#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#define MIN(a,b) ((a < b) ? a : b )

using namespace std;

int H, W, temp;
vector<int> v[102];
int ans[102][102];
int check[102][102];
queue<pair<int,int> > q;
int ax[4] = { -1, 0, 1, 0};
int ay[4] = { 0, 1, 0, -1};

void input(){
    scanf("%d %d", &H, &W);

    for(int i = 0 ; i <= H+1 ; i++){
        for(int j = 0 ; j <= W+1 ; j++){
            if(i == 0 || j == 0 || i == H+1 || j == W+1){
                v[i].push_back(-1);
            }
            else{
                scanf("%1d", &temp);
                v[i].push_back(temp);
            }
        }
    }
}

void bfs(){
    pair<int, int> pi;
    ans[1][1] = 1; //처음 한칸
    check[1][1] = 1; //방문함
    q.push(make_pair(1,1));

    int x,y;

    while(!q.empty()){
        
        pi = q.front();
        q.pop();
        // cout << "pi: " << pi.first  << " " << pi.second << endl;

        for(int i = 0 ; i < 4 ; i++){
            
            x = pi.first + ax[i];
            y = pi.second + ay[i]; //좌표

            int now_val = v[pi.first][pi.second];
            int now_ans = ans[pi.first][pi.second];
            int next_val = v[x][y];
            int next_ans = ans[x][y];

            // cout << "now_ans: " << now_ans << endl;
            // cout << x << " " << y << endl;
            
            
            if(next_val == 1){ //길 있는 경우
                if(next_ans == 0){ //최소값 이 0이면 , 방문안함-> 넣기
                    q.push(make_pair(x,y));
                    ans[x][y] = now_ans + 1;
                }
                else{
                    next_ans = MIN(now_ans+1, next_ans); // 현재꺼랑 이전꺼 중에 작은 값을 넣기
                }
            }
        }
    }
    
}

void printarr(){ //배열 출력하기
    for(int i = 0 ; i <= H+1 ; i++){
        for(int j = 0 ; j <= W+1 ; j++){
            printf("%d ", ans[i][j]);
        }
        cout << endl;
    }
}

int main(){
    input();

    bfs();

    // printarr();

    cout << ans[H][W] << endl;


    
}