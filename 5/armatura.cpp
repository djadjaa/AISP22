//celobrojni kolicnik-> (duzina/zeljena duzina)=toliko delova koje ce saberemo i dobicemo maksimalan broj delova takvih da izgradimo najvecu duzinu stuba
//pretraga po resenju zadatka
//slozenost zavisi od resenja jer idemo dokle god ne nadjemo na duziinu koja ne ispunjava uslov: O(n*maxs)
//moramo naci gornje ogranicenje za maxS -> maxD(najveci stub od datih) -> O(n*maxD)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool provera(int n, vector<int64_t> komadi, int64_t k, int64_t stub){ //da li mozemo napraviti stub odredjene duzine
    //nismo stavili referencu
    int64_t komadaDuzineS=0;
    for(auto komad : komadi){
        komadaDuzineS += komad/stub;
    }
    return komadaDuzineS >= k;
}

int main(){

    int n;
    cin >> n;
    vector<int64_t> komadi(n); //long long 64bit tip
    for(int i=0; i<n; i++){
        cin >> komadi[i];
    }
    int64_t k;
    cin >> k;
    /*NETACNO RESENJE
    int64_t stub = 1;
    while(provera(n, komadi, k, stub){
        stub++;
    }
    //petlja se zaustavlja kada je provera false
    */

    int64_t l=1, d=*max_element(begin(komadi),end(komadi)); //dereferenciramo iterator kako bismo dobili vrednost
    int64_t resenje=0;
    while(l<=d){
        int64_t s=(l+d)/2;
        if(provera(n,komadi,k,s)){
            l=s+1;
            resenje=s;
        }else{
            d=s-1;
        }
    }
    cout << resenje << '\n';
    return 0;
}
//koristicemo binarnu pretragu zato sto redom prolazimo kroz niz stubova za koje je moguce podeliti date na nekoliko komada tako da mozemo napraviti onaj koji je najveci
//kada l i d zamene mesta dobijamo prazni interval i  resenje je d (l>d) u tom slucaju
//l=1 (najmanji stub je duzine 1), d=maxD
//tada ce slozenost zapravo biti O(nlogmaxD)
//prvih nekoliko ispunjava
