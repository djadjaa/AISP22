//sortirati, ukloniti duplikate pa pronaci nizove uzastopnih brojeva
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> niz(n);
    for(int i=0; i<n; i++){
        cin >> niz[i];
    }
    sort(begin(niz),end(niz));
    auto it = unique(begin(niz),end(niz)); //vraca iterator na pocetak duplikata
    niz.erase(it,end(niz)); //uklanja duplikate od tog iteratora pa sve do kraja
    n=niz.size();
    //ili niz.erase(unique(begin,end),end);
    //pamtimo duzinu i pocetak
    int duzina=1,pocetak=0; //niz ima barem jedan elem
    int maxDuzina=1,maxPocetak=0;
    for(int i=1; i<n; i++){
        if(niz[i]-niz[i-1]==1){
            duzina++;
        }else{
            duzina=1;
            pocetak=i; //trenutni pocetak (indeks trenutno prvog)
        }
        if(duzina>maxDuzina){
            maxDuzina=duzina; //koliko elem imamo
            maxPocetak=pocetak;
        }
    }
    for(int i=maxPocetak; i<maxPocetak+maxDuzina; i++){
        cout << niz[i] << '\n';
    }
    return 0;
}
