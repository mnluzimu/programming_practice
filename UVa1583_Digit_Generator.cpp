#include <cstdio>
#include <iostream>
using namespace std;

int digit(int n){
    int ans = n;
    while(n){
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

int main(){
    int T, n;
    int t;
    int i;
    cin >> T;
    while(T--){
        cin >> n;
        for(i = 0; i <= n; i++){
            t = digit(i);
            if(t == n){
                cout << i << endl;
                break;
            }
            else if(t > n){
                cout << '0' << endl;
                break;
            }
        }
    }
    return 0;
}