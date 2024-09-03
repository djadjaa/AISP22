/*
 n=2
 00
 01
 11
 10
 ako je n=3
 000
 001
 011
 010
 110
 111
 101
 100
 svaka susedna dva se razlikuju za tacno 1 mesto
 potrebno je zapisati k-ti broj grejovog koda reda n
 imacemo 2^n elemenata grejovog koda
 slozenost O(n*2^n)
 k>=m/2 -> 1 (n'=n--,k'=m-1-k)
 inace je 0 (n'=n--, k ostaje isti)
 (pri cemu je m br elem grejovog koda)
 prva cetiri bita su ekv poslednja 4 koji su u obrnutom poretku
 k'+k=m(duzina koda)-1 (jer je indeksirano od 0) -> k' = m-1-k
 npr n=3,k=6 -> n=2,k=1 (8-1-6) -> n=1,k=1 -> n=0,k=0 (zaustavljamo se kada je n=0)
 */

#include <iostream>

using namespace std;

string f(unsigned n, unsigned k){ //smanjujemo red grejovog koda
    if(n==0){
        return ""; //izlazak iz rekurzije
    }
    unsigned m=1u << n; //m/2
    if(k<(1u << (n-1))){ //m/2
        return "0"+f(n-1,k);
    }else{
        return "1"+f(n-1,m-1-k); //2*m
    }
}

int main(){

    unsigned n,k,m;
    cin >> n >> k;
    //binarni br cemo reprezentovati kao string

    cout << f(n,k) << '\n';
    return 0;
}
