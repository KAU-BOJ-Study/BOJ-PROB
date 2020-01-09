//온라인 저지에 가입한 사람들의 나이와 이름이 가입한 순서대로 주어진다.
//이때, 회원들을 나이가 증가하는 순으로,
//나이가 같으면 먼저 가입한 사람이 앞에 오는 순서로 정렬하는 프로그램을 작성하시오.

//struct , sort 사용

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct member{
    int age;
    string name; //char name[101] 로는 할 수 없는가?
    int join; //sort를 사용하기 위해 가입한 순서도 저장해주어야한다.
};

bool cmp(member a, member b){
    if(a.age < b.age) return true; //나이가 적은 순
    else if(a.age == b.age) {  //나이가 같으면 가입일이 작은 순
       if(a.join < b.join) return true;
       else return false; 
    }
    else return false;
}


int main(){
    int T;
    scanf("%d", &T);
    vector<member> a(T); 
    for(int i = 0 ; i < T ; i++){
        cin >> a[i].age >> a[i].name;
        // scanf("%d %s", &a[i].age, a[i].name);
        // scanf 는 string을 받을 수 없나? getline 등으로 가능, 그래서, char 형으로 하려고 한 것
        a[i].join = i;
    }

    // sort(a.begin(), a.end(), [](member a, member b){
    //     return (a.age < b.age) || (a.age == b.age && a.join < b.join)
    // }) => 람다함수 에러나는 이유?

    sort(a.begin(), a.end(), cmp);

    for(int i  = 0 ; i < T ; i++){
        printf("%d %s\n", a[i].age, a[i].name.c_str());
        //c_str() : string -> char * 로 변환하는 함수
    }
    return 0;
}