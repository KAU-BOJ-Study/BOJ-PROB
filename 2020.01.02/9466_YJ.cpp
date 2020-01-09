#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int check[100001] = { 0,}; //방문 순서을 체크
int s[100001] = { 0,}; //몇 번째 탐색인지를 저장 
// int done[100001] = { 0,};
vector<int> v[100001]; //입력받는 배열

int in_team = 0; //team이 이루어진 사람의 수
int visit = 1;// 방문순서
int searchT = 1; //탐색의 수


void dfs(int x){
    s[x] = searchT; //방문 순서
    check[x] = visit++; //방문함
    // printf("%d ", x);
    int next = v[x][0]; //다음 탐색 노드
    if(check[next] == 0){ //방문하지 않았으면 방문하기
        dfs(next);
    }else{ //전체에서 한번 방문한 적 있는 상태에서
        if(s[next] == searchT){ // 이번 턴에 방문함 -> 사이클임
            in_team += visit - check[next]; //이번턴에서 팀을 이룬 사람 만큼 추가
        }
        //전체에서 방문한 적 있는데, 이번턴에는 방문하지 않았으면 방문하지 않음.
    }
}

int main(){
    int T, n, temp;

    scanf("%d", &T); //테스트 횟수
    for(int t= 0; t<T ; t++){
        scanf("%d", &n); //총 명수
        for(int i = 1 ; i <= n ; i++){ //연결 리스트 형식의 그래프 만들기
            scanf("%d", &temp);
            v[i].push_back(temp);
        }

        for(int i = 1 ; i <= n ; i++){
            if(check[i] == 0){
                dfs(i);
                // printf("\n");
                visit = 1;
                searchT++;
                // printf("team : %d\n", in_team);
            }
        }
        printf("%d\n", n - in_team);

        for(int i = 1 ; i <= n ; i++){ //그래프, 정답, done배열 초기화
            v[i].clear();
        }
        memset(check, 0, sizeof(check)); 
        memset(s,0, sizeof(s));
        in_team = 0;
        searchT = 1;
    }
    

    //1 -> 3 -> 3 cycle 
    // 4 -> 5-> 6 -> 4 나오면 ch4 = 1, done=0인 상태에서 done=1로 바꿔주고, cnt++ -> 5 cnt++ -> 6 cnt++ done= 1
    // -> 4 둘다 1이니까 사이클 끝! 팀을 이룬 사람ans에 더해준다. ans = 3 
    // ch[1] = 1;
    // done[3] = 1; done = 1 and ch = 1 인경우 방문하지 않음 
    return 0;
}