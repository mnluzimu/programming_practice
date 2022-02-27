#include <iostream>
#include <map>
#include <string>
using namespace std;

map<char, char> match = {
    {'A','A'},{'E','3'},{'H','H'},{'I','I'},{'J','L'},{'L','J'},{'M','M'},{'O','O'},
    {'S','2'},{'T','T'},{'U','U'},{'V','V'},{'W','W'},{'X','X'},{'Y','Y'},{'Z','5'},
    {'1','1'},{'2','S'},{'3','E'},{'5','Z'},{'8','8'}
};

int main(){
    string s;
    int flag_p, flag_m;
    while(getline(cin, s)){
        flag_p = flag_m = 1;
        for(int i = 0; i < s.size() / 2; i++){
            if(s[i] != s[s.size() - 1 - i])
                flag_p = 0;
            if(match.find(s[i]) == match.end() || match[s[i]] != s[s.size() - 1 - i])
                flag_m = 0;
        }
        if(flag_p && flag_m){
            cout << s << " -- is a mirrored palindrome.\n";
        }
        else if(flag_p){
            cout << s << " -- is a regular palindrome.\n";
        }
        else if(flag_m){
            cout << s << " -- is a mirrored string.\n";
        }
        else{
            cout << s << " -- is not a palindrome.\n";
        }
    }
}