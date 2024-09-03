#include <iostream>
#include <string>

using namespace std;

void binniz(string &s, int64_t poz){
    if(poz==s.size()){ //ako smo stigli do kraja
        cout << s << '\n';
        return;
    }
    if(s[poz]=='.'){ //ako je mesto prazno
        s[poz]='0';
        binniz(s,poz+1); //stavljamo 0 i idemo dalje
        if(s[poz-1]!='1' && s[poz+1]!='1'){ //ako nema susednih jedinica mozemo da je stavimo bezbedno
            s[poz]='1';
            binniz(s,poz+1); //i idemo dalje
        }
        s[poz]='.'; //na ostatak stavimo tacke
    }else{ //ako je popunjeno idemo dalje
        binniz(s,poz+1);
    }
}

int main(){

    string s;
    cin >> s;
    binniz(s,0);

    return 0;
}
