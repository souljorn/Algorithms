#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

/*
Add `int max_of_four(int a, int b, int c, int d)` here.
*/
int max_of_four(int a, int b, int c, int d){
    
vector<int> num ={a, b, c, d};
int temp;    
    for(int i = 0; i < num.size()-1; i++){
        if(num[i] > num[i+1]){ 
            temp = num[i+1];
            num[i+1] = num[i];
            num[i] = temp;    
        }
    }
    return num.back();
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}
