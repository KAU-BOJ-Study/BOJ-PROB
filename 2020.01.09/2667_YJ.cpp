#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> d[27];
int check[27][27]; //방문했는가
int dan_num = 0; //단지 번호
int dan_peo = 0; //세대 인원
vector<int> dan_people; //세대 갯수 넣기 -> 나중에 sort() 할것임



void dfs(int x, int y){
    check[x][y] = 1; //방문했음!
    dan_peo++; //세대 하나 추가

    // cout << x << "," << y << '\n';
    // cout << check[x-1][y] << "," << check[x+1][y] << "," << check[x][y-1] << "," << check[x][y+1] << '\n';
    // cout << d[x-1][y] << "," << d[x+1][y] << "," << d[x][y-1] << "," << d[x][y+1] << '\n';

    //상
    if(check[x-1][y] == 0){ //방문을 안함
        if(d[x-1][y] == 1){ //집이 있음
            dfs(x-1,y);
        }
        else check[x-1][y] = 1; //집이 없으면 방문만 했음을 표시
    }

    if(check[x+1][y] == 0){ //하
        if(d[x+1][y] == 1){
            dfs(x+1,y);
        }
        else check[x+1][y] = 1;
    }

    if(check[x][y-1] == 0){ //좌
        if(d[x][y-1] == 1){
            dfs(x,y-1);
        }
        else check[x][y-1] = 1;
    }

    if(check[x][y+1] == 0){ //우
        if(d[x][y+1] == 1){
            dfs(x,y+1);
        }
        else check[x][y+1] = 1;
    }

}
int main(){
    int N, temp;
    scanf("%d", &N);
    for(int i = 0 ; i <= N+1 ; i++){ //배열을 입력 받음
        for(int j = 0 ; j <= N+1 ; j++){
            if(i == 0 || j == 0 || i == N+1 || j == N+1) d[i].push_back(0); //0 인덱스는 0으로 채움 
            else{
                scanf("%1d", &temp);
                d[i].push_back(temp);
                // printf("%d ", d[i][j]);
            }
        }
    }

    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= N ; j++){
            if(check[i][j] == 0 && d[i][j] == 1){ //방문하지 않고, 집이 있는 곳만 방문
                dfs(i,j); //(1,1) ~ (N,N)까지 반복함
                dan_people.push_back(dan_peo);
                dan_peo = 0;
                // cout<< i << " " << j << endl;
            }
        }
    }

    cout << dan_people.size() << '\n';

    sort(dan_people.begin(), dan_people.end());

    int size = dan_people.size();
    for(int i = 0 ; i < size ; i++){
        cout << dan_people[i] << '\n';
    }

    return 0;
}

//x == 0 or y == 0 인경우, 검사하지 않음
//d[x][y] 부터 검사 -> check = 1, 단지번호 부여(dfs하나가 끝날 때 ++), 세대 ++(dfs끝날때 초기화 및 저장)
    // d = 0이면 넘어감
    // d = 1이면 검사 -> 단지번호 주어짐  , 몇 세대인지 더하기 시작
        // d[x-1][y] : 상
        // d[x+1][y] : 하
        // d[x][y-1] : 좌
        // d[x][y+1] : 우
            // 각 방향을 검사하여, 단지 인원을 더하기
                // d=1이고,check =0이면, dfs 
                // 0 이면, 안하고 check = 1로 바꿈(집은 없지만 방문은 했음)