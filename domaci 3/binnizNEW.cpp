#include <bits/stdc++.h>

using namespace std;

//BACKTRACKING
void binarniniz(string &s, int i){
    if(i==s.size()){
        cout << s << endl;
        return;
    }
    if(s[i]=='.'){
        s[i]='0';
        binarniniz(s,i+1); //leva strana
        if(s[i-1]!='1' && s[i+1]!='1'){ //ako nije uzastopna jedinica (..1.1..)
            s[i] = '1';
            binarniniz(s,i+1);
        }
        s[i]='.'; //ostatak niza
    }else{ //ako je sve popunjeno idemo dalje
        binarniniz(s,i+1);
    }
}

int main(){

    string s;
    cin >> s;
    binarniniz(s,0);

    return 0;
}
