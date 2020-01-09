#include <stdio.h>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

// vector<int> v[10000];
int check[6000000] = {0,}; //방문한 순서를 저장
int main(){
    int A, P;
    int in_cnt = 1;
    scanf("%d %d", &A, &P); //입력
    check[A] = in_cnt; //첫번째로 방문함
    int cal = A; //계산할 값은 초기에 입력받은 값
    int n = 0;
    int temp = 0; //계산한 값을 가질 값
    
    while(1){
        in_cnt++; //다음 방문
        
        do{
            n = cal%10;
            cal = cal / 10;
            temp += pow(n,P);
            printf("   Temp : %d\n", temp);
        }while(cal > 0); //숫자를 생성
                //cal % 10 != 0 일때는 왜 안되나. 10인 경우 한번 더 수행하지 않음


        if(check[temp] == 0){ //방문 안했음
            printf("Temp1 : %d\n", temp);
            check[temp] = in_cnt;
            cal = temp;
            temp = 0;
        }else{ //나왔던 숫자라면
            // printf("Temp2 : %d %d\n", temp, check[temp]);
            printf("%d\n", check[temp]-1);
            break;
        }
        
        
    }

    return 0;
}