#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

void init();

vector<int> d[52];
int check[52][52]; //방문했는가
int dan_num = 0; //단지 번호
int isl = 0; //세대 인원
vector<int> dan_people; //세대 갯수 넣기 -> 나중에 sort() 할것임
int H, W; //너비 높이

int dx[] = {0,0,1,-1,-1,-1,1,1};
int dy[] = {1,-1,0,0,-1,1,-1,1};


void dfs(int x, int y){
    check[x][y] = 1; //방문했음!

    // cout << x << "," << y << '\n';
    // cout << check[x-1][y] << "," << check[x+1][y] << "," << check[x][y-1] << "," << check[x][y+1] << '\n';
    // cout << d[x-1][y] << "," << d[x+1][y] << "," << d[x][y-1] << "," << d[x][y+1] << '\n';

    int nx ,ny;
    
    for(int i = 0; i < 8 ; i++){
        nx = x + dx[i];
        ny = y + dy[i];

        if(check[nx][ny] == 0){ //방문을 안함
            if(d[nx][ny] == 1){ //땅이 있음
                dfs(nx,ny);
            }
            else check[nx][ny] = 1; //땅이 없으면 방문만 했음을 표시
        }
    }
}
int main(){
    int temp;
    while(1){
    scanf("%d %d", &H, &W);
    if(H == 0 && W == 0) return 0;
    for(int i = 0 ; i <= W+1 ; i++){ //배열을 입력 받음
        for(int j = 0 ; j <= H+1 ; j++){
            if(i == 0 || j == 0 || j == H+1 || i == W+1) d[i].push_back(0); //0 인덱스는 0으로 채움 
            else{
                scanf("%d", &temp);
                d[i].push_back(temp);
                // printf("%d ", d[i][j]);
            }
        }
    }

    // for(int i = 0 ; i <= W+1 ; i++){ //배열 출력
    //     for(int j = 0 ; j <= H+1 ; j++){
    //         // if(i == 0 || j == 0 || i == H+1 || j == W+1) d[i].push_back(0); //0 인덱스는 0으로 채움 
    //         // else{
    //             // scanf("%d", &temp);
    //             // d[i].push_back(temp);
    //             printf("%d ", d[i][j]);
    //         // }
    //     }
    //     cout << '\n';
    // }
    /*
    출력예시 : 
    0 0 0 0 0 0 0 
    0 1 0 1 0 0 0 
    0 1 0 0 0 0 0 
    0 1 0 1 0 1 0 
    0 1 0 0 1 0 0 
    0 0 0 0 0 0 0 

    주변이 0으로 둘러싸고 있음
    */
    

    for(int i = 1 ; i <= W ; i++){
        for(int j = 1 ; j <= H ; j++){
            if(check[i][j] == 0 && d[i][j] == 1){ //방문하지 않고, 집이 있는 곳만 방문
                dfs(i,j); //(1,1) ~ (N,N)까지 반복함
                isl++;
            }
        }
    }

    cout << isl << '\n';

    
    init(); //초기화

    }

    return 0;
}

void init(){ 
    //벡터 초기화
    for(int i = 0 ; i<=W+1 ; i++){
        d[i].clear();
    }
    //섬 갯수 초기화
    isl = 0;
    //체크 배열 초기화
    memset(check,0, sizeof(check));
}

//x == 0 or y == 0 인경우, 검사하지 않음
//d[x][y] 부터 검사 -> check = 1, 단지번호 부여(dfs하나가 끝날 때 ++), 세대 ++(dfs끝날때 초기화 및 저장)
    // d = 0이면 넘어감
    // d = 1이면 검사 -> 단지번호 주어짐  , 몇 세대인지 더하기 시작
        // d[x-1][y] : 상
        // d[x+1][y] : 하
        // d[x][y-1] : 좌
        // d[x][y+1] : 우
        // d[x-1][y-1] : 대각선 위 왼쪽
        // d[x-1][y+1] : 대각선 위 오른쪽
        // d[x+1][y-1] : 대각선 아래 왼쪽
        // d[x+1][y+1] : 대각선 아래 오른쪽
            // 각 방향을 검사
                // d=1이고,check =0이면, dfs 
                // 0 이면, 안하고 check = 1로 바꿈