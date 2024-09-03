#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char suprotanSmer(char c){
    switch(c){
        case 'L':
            return 'R';
        case 'R':
            return 'L';
        case 'U':
            return 'D';
        case 'D':
            return 'U';
    }
    return 0;
}

int main(){

    string str;
    cin >> str;
    string s;
    for(char c:str){
        if(suprotanSmer(c)==s.back() && !s.empty()){
            s.pop_back();
        }else{
            s.push_back(c);
        }
    }
    cout << s << endl;
    return 0;
}
