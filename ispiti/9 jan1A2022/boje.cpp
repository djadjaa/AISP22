#include <bits/stdc++.h>

using namespace std;

//formiramo prvo one koje počinju sa c pa sa p pa sa z
void boje(string &s, int ind, bool sveBoje){
    if(ind==s.size()){
        if(sveBoje && s[ind-1]!=s[0]) //da li se razlikuju susedne dve i da li su sve boje iskorišćene
            cout << s << endl;

        return;
    }
    for(char c:{'c','p','z'}){
        if(s[ind-1]!=c){ //ako nije iskorišćena
            s[ind]=c;
            boje(s,ind+1, sveBoje || c!=s[0] && c!=s[1]); //da li imamo sve boje ili da li smo iskoristili dve boje od 3 (dakle da li nam je preostala treća)
        }
    }
}

int main(){

    int64_t n;
    cin >> n;
    string s(n+1,' ');
    for(char c:{'c','p','z'}){
        s[0] = c;
        boje(s,1,false);
    }

    return 0;
}
