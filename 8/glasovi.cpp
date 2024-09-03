/*
 map-preslikavanje u mat smislu
 svaki elem slikamo u neku vrednost(kljuc i vrednost)
 m[x]=y -> u mapi m postavi vrednost kljuca x na y
 npr m["pera"]=1; m["pera"]++;
 m.erase(x) - brise se kljuc (moze i m.find())
 sve operacije mape su slozenosti o(logn)
 nebitan je poredak stringova, vec koliko su se stringovi pojavili( tj elementi )
 */
//u ovom slucaju slikacemo imena studenata u glasove i sortiracemo ih
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int main(){

    int n;
    cin >> n;
    map<string,int> brojGlasova;//prvi arg je tip kljuca, pa tip vrednosti
    string ime;
    while(n--){
        cin >> ime;
        brojGlasova[ime]++;
        /*
         {}
         m[pera]++; -> prvo izracunava m[pera] tj dodaje pera u mapu, a zatim vrednost se uvecava jer je podrazumevana vr 0=> m={pera,1}

         nije neophodno:
         if(brojGlasova.find(ime)==end(brojGlasova)){
            brojGlasova[ime]=1;
        }
        jer u petlji svako dobija po jedan glas
         */
    }
    int maxPoj=0;
    //ne ide po kljucevima nego po parovima neke vrednosti(gde je prvi arg kljuc a drugi vr):
    for(pair<string,int> p:brojGlasova){ //moze i auto p jer ce program da odredi koja je vr u pitanju
        maxPoj = max(maxPoj,p.second);//p.second je broj glasova tj vrednost u mapi
    }
    cout << maxPoj << '\n';
    return 0;
}
//ceo program je slozenosti o(nlogn) u najgorem a u najboljem o(nlogm) pri cemu je m br kljuceva-> slozenost ce zavisiti od br razlicitih imena
