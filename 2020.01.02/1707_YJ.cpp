//이분 그래프
#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> v[20001]; //정점의 최대값 20000
int check[20001]; //0방문안함,1그룹,2그룹

//깊이 우선 탐색
void dfs(int x, int ch){ 
    for(int i = 0 ; i < v[x].size() ; i++){
        int next = v[x][i];
        if(check[next] == 0){ //방문 안했으면 방문하자.
            check[next] = 3 - check[x]; //1이면 2, 2이면 1
            dfs(next, check[next]); 
        }
    }

}
int main(){

    int T, n, m, x, y;
    string ans = "YES"; //디폴트는 YES
    scanf("%d", &T);
    for(int i = 0 ; i < T ; i++){
        scanf("%d %d", &n, &m); //정점, 간선 갯수 입력
        memset(check, 0, sizeof(check)); // 초기화 필수!!
        for(int j = 0 ; j < m ; j++){
            scanf("%d %d", &x, &y); // 간선 입력
            v[x].push_back(y);
            v[y].push_back(x);
        } 
        //탐색
        for(int j = 1 ; j <= n ; j++){ //연결 그래프가 아닐 수 도 있으므로, 모든 노드를 탐색해야한다.
            if(check[j] == 0){
                check[j] = 1; //처음 탐색하는 노드는 1그룹에 넣음
                dfs(j, check[j]);
            }
        }

        for(int k = 1 ; k <= n ; k++){ //각 간선의 두 정점의 색이 다른지 검사
            for(int l = 0 ; l < v[k].size() ; l++){
                if(check[k] == check[v[k][l]]){ //색이 같으면 이분 그래프가 아님
                    ans = "NO";
                    break;
                }
            }
        }
        printf("%s\n", ans.c_str());
        ans = "YES"; //초기화 필수
        
        for(int d = 0 ; d <= n ; d++){
            v[d].clear(); //test case 마다 초기화는 필수
        }
    }

    return 0;
}