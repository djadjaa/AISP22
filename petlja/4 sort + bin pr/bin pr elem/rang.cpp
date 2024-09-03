#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Studenti{
    string ime;
    int64_t poeni;
};
/*
bool poredi(const Studenti &a, const Studenti &b){
    if(a.poeni > b.poeni)
        return true;
    else
        return false;
}
*/
int main(){

    int64_t n;
    cin >> n;
    vector<Studenti> st(n);
    vector<int64_t> poeni(n); //zarad lakše pretrage starog ranga
    for(int i=0; i<n; i++){
        cin >> st[i].ime >> st[i].poeni;
        poeni[i] = st[i].poeni;
    }
    sort(begin(poeni),end(poeni),less<int64_t>());

    /*
    Pera 85
    Ana 93
    Jelena 90
    Mika 72
    Lidija 75
---sort po poenima i pamtimo stare pozicije---
    Ana 93 (2)
    Jelena 90 (3)
    Pera 85 (1)
    Lidija 75 (5)
    Mika 72 (4)

    sortirani poeni: 93 90 85 75 72
    niz poena: 85 93 90 72 75

    i preko iteratora tražimo gde se nalazi tekući član niza poena i ispišemo poziciju na kojoj se nalazi:
     */

    for(Studenti x : st){ //za svakog studenta preko iteratora i donjeg ogranicenja trazimo prvobitni rang
        vector<int64_t>::iterator it;
        it = lower_bound(begin(poeni),end(poeni),x.poeni); //tražimo kroz sortirane poene željeni poen i poziciju na kojoj se nalazi željeni poen i time dobijamo trenutni rang
        int64_t rang = poeni.end() - it;
        cout << x.ime << " " << rang << endl;
    }
    return 0;
}
