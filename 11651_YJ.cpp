//11651 STL struct 사용
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
struct Point{  //좌표를 구조체 형식으로 생성
    int x,y;
};

bool cmp(Point &a, Point &b){ //bool함수라는 점
    if(a.y < b.y){ //오름차순
        return true;
    }else if(a.y == b.y){ //y좌표가 같으면 x좌표 오름차순
        if(a.x < b.x){
            return true;
        }
        else{ return false;}
    }else return false;
}

int main(){
    int T;
    scanf("%d", &T);
    vector<Point> v(T); //Point 자료형을 가진 T크기의 벡터 생성
    
    for(int i = 0 ; i < T ; i++){
        scanf("%d %d", &v[i].x, &v[i].y); 
    }

    // cout << v.size() << '\n';

    sort(v.begin(), v.end(), cmp); //cmp함수를 사용해서 정렬

    for(int i = 0 ; i < T ; i++){
        printf("%d %d\n", v[i].x, v[i].y);
    }

    return 0;
}