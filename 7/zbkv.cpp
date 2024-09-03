/*
 vreme - o(n^2logn)
 prostor -o(n^2)
 da bismo ovo poboljsali m sortiranih nizova sa n elem spojicemo ih u jedan preko reda sa prioritetom pri cemu cemo pamtiti samo elemente oblika (n,n) pa u zavisnosti od sume izbacujemo taj element pa ubacujemo minimalni
 */

#include <iostream>
#include <queue>
using namespace std;

int suma(pair<int,int>p){
    return p.first * p.first + p.second * p.second;
}

struct comparator{
    //cmp
    //ako zelimo minimum u redu sa prioritetom tada znacenje ove fje treba da bude sledece:
    //true ako nakon sortiranja a treba da bude ispred b
    //true ako b treba da bude na vrhu a ne a
    //dakle ako je x>y tada je true inace false
    bool operator()(pair<int,int>a, pair<int,int>b){
        if(suma(b) < suma(a)){ //obrcemo uloge jer trazimo najmanji a ne najveci elem
            return true;
        }
        else if(suma(b) > suma(a)){
            return false;
        }
        return b.first < a.first;
    }
};

int main(){

    int n,k;
    cin >> n >> k; //n je dokle idu koordinate, k je koliko elem niza moramo da generisemo
    priority_queue < pair<int, int>, vector<pair<int,int>> , comparator> parovi; //isto je kao da smo napravili sami strukturu
    //prvi arg je tip koji smestamo u red, drugi tip je tip gde se smestaju elementi
    for(int i=0; i<=n; i++){
        parovi.push({i,i}); //parovi sa dijagonale
    }
    //vadimo najmanji iz reda,izbacujemo ga u drugu listu i dodajemo u red naredni uvecanjem druge koordinate
    pair<int,int> temp;
    while(k--){ //generisemo k elemenata
        temp = parovi.top();
        parovi.pop();
        if(temp.second < n){ //ukoliko nismo stigli do kraja liste
            parovi.push({temp.first,temp.second+1});
        }
    }
    temp = parovi.top();
    cout << temp.first << ' ' << temp.second << ' ' << suma(temp) << '\n';
    return 0;
}
