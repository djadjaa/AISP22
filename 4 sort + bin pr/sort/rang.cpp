#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Ucenici{
    string ime;
    int64_t poeni,stariRang,noviRang;
};

bool porediPoene(const Ucenici &a, const Ucenici &b){
    if(a.poeni > b.poeni)
        return true;
    else
        return false;
}

bool porediPoz(const Ucenici &a, const Ucenici &b){
    if(a.stariRang < b.stariRang)
        return true;
    else
        return false;
}

int main(){

    int64_t n;
    cin >> n;
    vector<Ucenici> u(n);
    for(int i=0; i<n; i++){
        cin >> u[i].ime >> u[i].poeni;
        u[i].stariRang = i+1;
    }
    sort(begin(u),end(u),porediPoene);
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
     */
    for(int i=0; i<n; i++){
        u[i].noviRang = i+1;
    }
    sort(begin(u),end(u),porediPoz);

    /*
    Ana 93 (2)
    Jelena 90 (3)
    Pera 85 (1)
    Lidija 75 (5)
    Mika 72 (4)
---sort po starim pozicijama rastuće
    Pera 85 (nova poz: 3)
    Ana 93 (nova poz: 1)
    Jelena 90 (nova poz: 2)
    Mika 72 (nova poz: 5)
    Lidija 75 (nova poz: 4)
     */

    for(int i=0; i<n; i++){
        cout << u[i].ime << " " << u[i].noviRang << endl;
    }
    return 0;
}
