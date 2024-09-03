#include <iostream>
using namespace std;
void zagrade(string& sablon, string& niz, int i, int brotv){
    if(brotv<0) //broj otvorenih
        return;
    if(i==niz.size()){
        if(brotv==0) //tada smemo da ispisemo jer broj otvorenih odn zatvorenih mora biti jednak (odsecanje)
            cout << niz << '\n';
        return;
    }
    if(sablon[i]=='.' || sablon[i]=='('){ //tacka je izbor zagrada koja moze da stane
        niz[i]='(';
        zagrade(sablon,niz,i+1,brotv+1); //postavka zagrada levo
    }
    if(sablon[i]=='.' || sablon[i]==')'){
        niz[i]=')';
        if(brotv>0) //onda zatvori zagradu
            zagrade(sablon,niz,i+1,brotv-1); //postavka zagrada desno
    }
}
int main(){
    string sablon;
    cin >> sablon;
    string niz(sablon.size(),' '); //inicijalizacija
    zagrade(sablon,niz,0,0);
    return 0;
}
