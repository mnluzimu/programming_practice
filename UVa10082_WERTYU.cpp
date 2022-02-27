#include <iostream>
#include <map>
using namespace std;

map<char, char> match = {
    {'Q','\t'}, {'W', 'Q'}, {'E', 'W'}, {'R', 'E'}, {'T', 'R'}, {'Y', 'T'}, {'U', 'Y'}, {'I', 'U'}, {'O','I'}, {'P', 'O'}, {'[', 'P'}, {']', '['}, {'\\', ']'},
    {'S','A'},{'D', 'S'},{'F','D'},{'G','F'},{'H','G'},{'J','H'},{'J','H'},{'K','J'},{'L','K'},{';','L'},{'\'',';'},{'X','Z'},{'C','X'},{'V','C'},{'B','V'},{'N','B'},
    {'M','N'},{',','M'},{'.',','},{'/','.'}
};

int main(){
    char c;
    while((c = cin.get()) != EOF){
        if(match.find(c) != match.end()){
            cout << match[c];
        }
        else{
            cout << c;
        }
    }
    return 0;
}