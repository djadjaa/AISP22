/*
 0 1 2¹
 0 1 1 0
 0+0 0+1 1+1 1+0 2²
 0+00 0+01 0+11 0+10 1+10 1+11 1+01 1+00 2³
 naravno pozicije idu od nule

 ide niz 0 i 1
 zatim kada formiramo sledeći niz, dupliramo ga time što dodamo elemente u obrnutom poretku i na prvu polovinu dodamo 0 a na drugu 1
 dakle svaki niz ima veličinu 2^n

 primećujemo da prva polovina niza čini 2^n-1 elem tako da će k biti između 0 i 2^n-1 a u drugoj polovini od 2^n-1 do 2^n
 u prvoj polovini pozicija je k, u drugoj je 2^n -1 - k odn k':

 k+k'=2^n -1 ovoliko pozicija ima

 npr n=3, k=5: 2^n = 8 =>
 k je u drugoj polovini (k>2^n-1 => 5>2^3-1 => 5>4) pa pisemo 1 i k je 8-1-5=2, a n--
 n=2, k=2
 k je u drugoj polovini (k>=2^n-1 => 2>=2^2-1 => 2>=2) pa pisemo 1 i k=4-1-2=1 a n--
 n=1, k=1
 k je opet u drugoj polovini (1>=2^1-1 => 1>=1) pa pisemo 1 i k=2-1-1 a n--
 n je 0 i k=0 pa zaustavljamo program
 dobili smo 100
 */
#include <iostream>

using namespace std;

string f(unsigned n, unsigned k){
    if(n==0)
        return "";
    if(k<(1u << (n-1))) //k<2^n-1 (ako je u prvoj polovini)
        return "0"+f(n-1,k);
    else //druga polovina
        return "1"+f(n-1,(1u<<n)-1-k);
}

int main(){

    unsigned n,k;
    cin >> n >> k;
    cout << f(n,k) << endl;
    
    return 0;
}
