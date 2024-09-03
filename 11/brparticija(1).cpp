//2+1 <=> 1+2 - gledamo multiskup particija
//nije nuzno koji poredak particija gledamo
/*
 5
 1+1+1+1+1
 2+1+1+1
 2+2+1
 3+1+1
 3+2
 4+1
 5
 */
//delimo po pocetnoj vrednosti i rekurzivno generisemo particije prethodnih vrednosti
//npr -> pocetna vrednost (2) + particije broja 3 (1+1+1 ili 2+1) tj multiskup tih particija
//ne mozemo iskorisiti particiju vrednosti >= od tekuce

#include <iostream>
using namespace std;
/*
 imacemo 2 dela skupa:
 1 deo gde su sabirci <= n-1, tamo ne koristimo n, podrazumevano je da su sabirci strogo manji od n
 2. deo gde su sve vrednosti 0 pri cemu su sabirci <= n, dakle oduzecemo od n maksimalni br sabiraka - to je nacin kako da zapisemo tu particiju
 */

int brParticija(int n,int maxSabiraka){ //n je broj particija koje zelimo da proucimo
    if(n==0){
        return 1; //jedna jedina particija(ako je multiskup prazan (zbir nicega je nula (neutral za sabiranje)))
    }
    int br=0;
    if(maxSabiraka>1) //broj ne moze biti i pozitivan i >= 0 jer minimalnu particiju mozemo praviti iskljucivo sa jedinicama
        br += brParticija(n,maxSabiraka-1); //gledamo particije gde su sabirci > 1
    if(maxSabiraka<=n)
        br += brParticija(n-maxSabiraka,maxSabiraka); //a ovde ako su <= n
        //prazan skup ne mozemo napisati kao sabirke, sto znaci da sabirci moraju biti pozitivni, a ako je n >= maksimalan br sabiraka mi mozemo iskoristiti i negativne brojeve u tom slucaju
    return br;
}

int main(){
    int n;
    cin >> n;
    cout << brParticija(n,n) << '\n';
    return 0;
}
