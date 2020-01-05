#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int T, temp;
    scanf("%d", &T);
    int a[10001] ={0,};
    
    for(int i = 0 ; i < T ; i++){
        scanf("%d", &temp);
        a[temp]++;
    }
    
    for(int i = 1 ; i <= 10000 ; i++){
        for(int j = 0 ; j < a[i] ; j++){
            printf("%d\n", i);
        }
    }
    return 0;
}