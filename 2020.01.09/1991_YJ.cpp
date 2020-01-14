#include <iostream>

using namespace std;

int tree[27][2];

char x, y, z;

void input(){
    int N = 0 ;
    scanf("%d", &N);
   
    for(int i = 0 ; i< N ; i++){
        scanf(" %c %c %c", &x, &y, &z);
        x = x - 'A';
        if(y == '.'){
            tree[x][0] = -1;
        }
        else tree[x][0] = y - 'A';

        if(z == '.'){
            tree[x][1] = -1;
        }
        else tree[x][1] = z - 'A';
    }
}

void preorder(int n){
    if(n == -1) return;
    cout << (char)(n + 'A');
    preorder(tree[n][0]); //왼쪽 트리
    preorder(tree[n][1]);
}

void inorder(int n){
    if(n == -1) return;
    inorder(tree[n][0]); //왼쪽 트리
    cout << (char)(n + 'A');
    inorder(tree[n][1]);
}

void postorder(int n){
    if(n == -1) return;
    
    postorder(tree[n][0]); //왼쪽 트리
    postorder(tree[n][1]);
    cout << (char)(n + 'A');
}


int main(){

    input();
    preorder(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);
    cout << '\n';
    // cout << y <<endl;
    return 0;
}