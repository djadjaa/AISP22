#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    long long k,rez;
    for(int i=0;i<n; i++){
        cin >> k;
        rez = (2*k-1)*((k*k)-k+1);
        cout << rez << '\n';
    }
    return 0;
}
/*
 svaki red k ima 2k-1 elemenata. poslednji element u svakom redu je kvadrat i vidimo da je u pitanju (k-1)². njegov sledbenik, odnosno prvi element je za 1 veći, tj. (k-1)²+1, dok je razlika između svakog elementa (tako i prethodnika i sledbenika) je 1.
 zbir elemenata u tom slučaju možemo odrediti preko formule za sumu aritmetičkog niza gde će se ovi gorenavedeni kriterijumi ispuniti:

 brelem*prvi+((brelem(brelem-1))/2*razlika

 kad sve zamenimo i sredimo jednakost dobijamo željenu formulu
 */
