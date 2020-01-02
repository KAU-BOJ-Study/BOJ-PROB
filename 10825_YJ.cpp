#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <tuple>

using namespace std;
struct st{
    string name;
    int k, e, m;
};

bool cmp2(st a, st b){
    return make_tuple(-a.k, a.e, -a.m, a.name) < make_tuple(-b.k, b.e, -b.m, b.name);
    //조건문이 많아서 복잡할 때는 tuple 을 사용해서 비교가 가능 (앞에서 부터 순서대로 비교해줌)
    //시간 좀 더 많이 걸림
}

bool cmp(st u, st v){
    if (u.k > v.k) {
        return true;
    } else if (u.k == v.k) {
        if (u.e < v.e) {
            return true;
        } else if (u.e == v.e) {
            if (u.m > v.m) {
                return true;
            } else if (u.m == v.m) {
                return u.name < v.name;
            }
        }
    }
    return false;
}

int main(){
    int T;
    scanf("%d", &T);
    vector<st> v(T);
    for(int i = 0 ; i < T ; i++){
        cin >> v[i].name >> v[i].k >> v[i].e >> v[i].m;
    }

    sort(v.begin(), v.end(), cmp2);

    for(int i = 0 ; i < T ; i++){
        // cout << v[i].name << '\n';
        printf("%s\n", v[i].name.c_str());
    }
    return 0;
}
