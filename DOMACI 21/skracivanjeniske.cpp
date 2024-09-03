#include <iostream>
#include <string>

//koristićemo operacije sa stringovima umesto sa stekom, jer kada bismo koristili stek čitali bi se rezultati odozgo ka dole umesto obrnuto
using namespace std;

int main(){

    string str;
    cin >> str;

    string s;
    for(char c:str){
        if(s.empty() || c!=s.back())
            s.push_back(c);
        else
            s.pop_back();
    }
    cout << s << endl;
    return 0;
}
