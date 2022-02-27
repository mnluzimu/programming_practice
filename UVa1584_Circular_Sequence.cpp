#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
#define maxn 105

int lesser(const char * s, int p, int q){
    int n = strlen(s);
    for(int i = 0; i < n; i++){
        if(s[(p + i) % n] != s[(q + i) % n])
            return s[(p + i) % n] < s[(q + i) % n];
    }
    return 0;
}

int main(){
    int T;
    char s[maxn];
    scanf("%d", & T);
    while(T--){
        scanf("%s", s);
        int ans = 0;
        int n = strlen(s);
        for(int i = 1; i < n; i++)
            if(lesser(s, i, ans))
                ans = i;
        for(int i = 0; i < n; i++)
            putchar(s[(i + ans) % n]);
        putchar('\n');
    }
    return 0;
}