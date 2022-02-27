#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int t;
    int flag;
    int cnt_strong, cnt_weak;
    int cnt = 0;
    vector<int> v;
    vector<int> v_cpy;
    vector<int> v1;
    cin >> n;
    while(n != 0){
        cnt++;
        cout << "Game " << cnt << ":\n";
        v.clear();
        for(int i = 0; i < n; i++){
            cin >> t;
            v.push_back(t);
        }
        flag = 1;
        while(flag){
            flag = 0;
            v_cpy = v;
            cnt_strong = cnt_weak = 0;
            v1.clear();
            for(int i = 0; i < n; i++){
                cin >> t;
                if(t != 0)
                    flag = 1;
                if(t == v[i]){
                    cnt_strong++;
                    vector<int>::iterator it = find(v_cpy.begin(), v_cpy.end(), t);
                    v_cpy.erase(it);
                }
                else
                    v1.push_back(t);
                // else if(find(v_cpy.begin(), v_cpy.end(), t) != v_cpy.end()){
                //     cnt_weak++;
                //     vector<int>::iterator it = find(v_cpy.begin(), v_cpy.end(), t);
                //     v_cpy.erase(it);
                // }
            }
            for(vector<int>::iterator it = v1.begin(); it != v1.end(); it++){
                if(find(v_cpy.begin(), v_cpy.end(), t) != v_cpy.end()){
                    cnt_weak++;
                    vector<int>::iterator it = find(v_cpy.begin(), v_cpy.end(), t);
                    v_cpy.erase(it);
                }
            }
            if(flag)
                printf("(%d, %d)\n", cnt_strong, cnt_weak);
        }
        cin >> n;
    }
    return 0;
}