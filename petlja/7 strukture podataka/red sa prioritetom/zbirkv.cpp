/*
 kako bismo spojili sortirane nizove u red sa prioritetom, posmatraćemo njihove prve elemente(sume na početku svakog od niza) i najmanji ubacujemo u red
 nećemo spajati ceo niz već do ktog i poslednji ispisujemo na standardni izlaz

 ti prvi elementi činiće jedan niz, u ovom slučaju biće sve dijagonale. koji element bude bio najmanji, stavimo ga u red sa prioritetom i u niz stavljamo sledeći iz niza u kom smo izvukli minimum koji se nalazi u redu sa prioritetom

 složenost će biti O(n) prostorna a vremenska O(klogn)
 */
#include <iostream>
#include <queue>

using namespace std;

int sum(pair<int,int>p){
    return p.first*p.first + p.second*p.second;
}
/*ako zelimo minimum u redu sa prioritetom tada poredimo da li je jedna suma veća od druge i tada vraćamo true (iako bi intuitivno trebalo obrnuto, ali tako red sa prioritetom funkcioniše
    */
struct comparator{
    bool operator()(pair<int,int> a, pair<int,int> b){
        if(sum(a) > sum(b))
            return true;
        else if(sum(a) < sum(b))
            return false;
        return b.first < a.first; //ako su im jednake sume, poredimo prvu koordinatu
    }
};

int main(){

    int64_t n,k;
    cin >> n >> k;
    //prvi arg je tip koji smestamo u red, drugi tip je tip gde se smestaju elementi
    //prvi arg će nam služiti da poredimo sume, a drugi arg da poredimo koordinate
    priority_queue < pair<int, int>, vector<pair<int,int>> , comparator> parovi;
    for(int i=0; i<=n; i++){
        parovi.push({i,i});
    }
    //dakle na početku imamo elemente (0,0) , (1,1) itd i poredimo ih
    pair<int,int> temp; //ovde ćemo čuvati rezultat
    while(k--){
        temp = parovi.top(); //vadimo najmanji iz reda
        parovi.pop(); //i izbacujemo ga
        if(temp.second < n){
            parovi.push({temp.first,temp.second+1}); //dodajemo u red naredni uvecanjem druge koordinate
        }
    }
    temp = parovi.top(); //najmanji do k-tog
    cout << temp.first << ' ' << temp.second << ' ' << sum(temp) << endl;
    return 0;
}
