//formula umesto petlje i uslova
#include <iostream>
using namespace std;
int main(){

    int a,b,k;
    cin >> a >> b >> k;
    int deljiviDoB = b/k+1;
    int deljiviDoA = (a-1)/k +1;

    //broj koraka bice b-a+1 => O(b-a)
    //po k elemenata bice poslednji iz tog segmenta deljiv sa k
    //npr k=3 -> svaki treci je deljiv sa 3
    //b/k -> broj malih segmenata duzine k koji mogu da stanu u segment duzine b pri cemu ako delimo bez ostatka dobijamo koliko celih malih segmenata mozemo staviti u segment b
    //dobijamo b/k+1 -> 1 jer ukljucujemo b
    //sve dok je fiksirana leva granica mozemo izracunati koliko br je deljivo sa k
    //[a,b]:[0,b]-[0,a-1] (oduzimamo ove pre a) -> b/k+1 - (a-1)/k+1 -> skraticemo keceve i dobijamo b/k-(a-1)/k -> b-a+1/k

    //problematicno je ako je a=0 jer dobicemo segment [0,-1] sto je prazan skup

    if(a>0)
        cout << deljiviDoB - deljiviDoA << '\n';
    else
        cout << deljiviDoB << '\n';
    return 0;
}
