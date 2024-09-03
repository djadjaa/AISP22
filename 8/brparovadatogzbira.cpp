/*
 * {1,2,3,3,1,2} <=> {1,2,3}
 insert(x)-dodaj x u skup, ako imamo uveliko taj elem nece se nista desiti inace ce se dodati; slozenost je o(logn), a u najboljem slucaju je o(1)
 erase(x)-uklanja elem iz skupa ako je taj elem uveliko u skupu
 find(x)-vraca iterator na vrednost x
 */

/*
 citamo elem po elem i gledamo elemente sa njegove leve str da li daje dati zbir, jer u tom slucaju nece se desiti ponavljanja
 pravimo skup procitanih elem
 koristicemo fju find, mi cemo uraditi sledece: elemskupa = zbir - trenutnielem
 slozenost je o(nlogn) (n jer prolazimo kroz ceo niz, a logn zbog fje find)
 */

#include <iostream>
#include <set>
using namespace std;
int main(){

    int s,n,x;
    cin>> s>> n;
    set<int>vrednosti;
    int brPar=0;
    while(n--){
        cin >> x;
        if(vrednosti.find(s-x)!=end(vrednosti)){
            brPar++;
        }
        vrednosti.insert(x);
    }
    cout << brPar << '\n';
    return 0;
}
