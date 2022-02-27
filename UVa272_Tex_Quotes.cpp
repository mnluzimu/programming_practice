#include <iostream>
using namespace std;

int main(){
    char c;
    int flag = 0;
    while((c = cin.get()) != EOF){
        if(c == '\"' && flag == 0){
            cout << "``";
            flag = 1;
        }
        else if(c == '\"' && flag == 1){
            cout << "\'\'";
            flag = 0;
        }
        else
            cout << c;
    }
    return 0;
}