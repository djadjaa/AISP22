#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int maxPalindrom(const string& s,int l,int d){
    if(l>d){//prazan string
        return 0;
    }
    if(l==d){ //ako je string jedan karakter
        return 1;
    }
    if(s[l]==s[d]){ //ako su dva karaktera iz stringa jednaka tada uvecavamo rezultat za 2 i idemo rekurzivno dalje uklanjajuci posmatrane karaktere
        return 2+maxPalindrom(s,l+1,d-1);
    }
    return max(maxPalindrom(s,l,d-1),maxPalindrom(s,l+1,d)); //inace odredjujemo maksimum ako uklonimo levi ili desni karakter jer nisu jednaki pa u tom slucaju ne mogu biti deo palindromskog podstringa
}

int main(){

    string s;
    cin >> s;
    cout << maxPalindrom(s,0,s.size()-1) << '\n';

    return 0;
}
