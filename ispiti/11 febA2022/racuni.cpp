/*
 6 4
marko 2
milan 5
dragana 4
upit 0
milan -1
upit 4
6 operacija, 4 korisnika
upit 0 -> rezultat biće 1 zato što 4. korisnik ima 0 dinara
upit 4 -> rezultat biće 2 zato što dragnana ima 4 dinara, a milan 5+-1

brIznosa[racun[s]]--;
racun[s] += x;
brIznosa[racun[s]]++;

marko 2
brIznosa[racun[marko]] = brIznosa[2] = -1
racun[marko] = 2
brIznosa[2] = 0

 */

#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int64_t n,k;
    cin >> n >> k;
    int64_t x;
    string s;
    unordered_map<string,int64_t> racun;
    unordered_map<int64_t,int64_t> brIznosa; //kljuc je br dinara a vrednost je onoliko koliko njih ima toliko dinara
    brIznosa[0] = k; //na početku svi imaju 0 dinara
    while(n--){
        cin >> s >> x;
        if(s=="upit"){
            cout << brIznosa[x] << endl;
        }
        else{
            //na pocetku podrazumevana vr kljuca je 0
            brIznosa[racun[s]]--; //umanjujemo br onih ciji je iznos 0
            /*
             * brIznosa[0]--
             */
            racun[s] += x;
            brIznosa[racun[s]]++; //uvecavamo br onih ciji je br dinara != 0
            /*
             brIznosa[x]++
             */
        }
        for(auto it = brIznosa.begin(); it != brIznosa.end(); it++)
            cout << "BR IZNOSA: " << it-> first << ' ' << it->second << endl;
        for(auto it = racun.begin(); it != racun.end(); it++)
            cout << "KORISNICI: " << it-> first << ' ' << it->second << endl;
    }

    return 0;
}

/*
 6 4
marko 2
BR IZNOSA: 2 1 - imamo 1 korisnika koji ima 2 din
BR IZNOSA: 0 3 - s obzirom na to da imamo 4 korisnika sa 0 dinara, posto marko ima 2, umanjujemo br takvih za 1
KORISNICI: marko 2
milan 5
BR IZNOSA: 5 1
BR IZNOSA: 2 1
BR IZNOSA: 0 2
KORISNICI: milan 5
KORISNICI: marko 2
dragana 4
BR IZNOSA: 4 1
BR IZNOSA: 5 1
BR IZNOSA: 2 1
BR IZNOSA: 0 1
KORISNICI: dragana 4
KORISNICI: milan 5
KORISNICI: marko 2
upit 0
1
BR IZNOSA: 4 1
BR IZNOSA: 5 1
BR IZNOSA: 2 1
BR IZNOSA: 0 1
KORISNICI: dragana 4
KORISNICI: milan 5
KORISNICI: marko 2
milan -1
BR IZNOSA: 4 2
BR IZNOSA: 5 0
BR IZNOSA: 2 1
BR IZNOSA: 0 1
KORISNICI: dragana 4
KORISNICI: milan 4
KORISNICI: marko 2
upit 4
2
BR IZNOSA: 4 2
BR IZNOSA: 5 0
BR IZNOSA: 2 1
BR IZNOSA: 0 1
KORISNICI: dragana 4
KORISNICI: milan 4
KORISNICI: marko 2
 */
