#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){

    string str;
    cin >> str;
    string s;
    for(char c:str){
        if(c!=s.back() || s.empty()){ //ako je novi karakter u pitanju
            s.push_back(c);
        }else{ //inace ako je duplikat brisemo ga
            s.pop_back();
        }
    }
    cout << s << endl;
    return 0;
}
