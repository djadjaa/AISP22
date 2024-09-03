/*
 * svodjenje na kanonski oblik (sortiranje i proveravanje da li su nizovi jednaki)
 * multiskup ne razlikuje poredak elem, vec koji su elem tu
 * insert(x) - dodaj jos jedan x
 * erase(x) - brise svaki elem koji se pojavljuje
 * erase(it) - brise dati elem
 * find(x) - vraca iterator na jedan od elemenata
 */
#include <iostream>
#include <set>
using namespace std;

int main(){

    int n,m,x;
    cin >> n;
    multiset<int> a;
    while(n--){
        cin >> x;
        a.insert(x);
    }
    cin >> m;
    multiset<int> b;
    while(m--){
        cin >> x;
        b.insert(x);
    }
    cout << (a==b ? "da" : "ne") << '\n';
    return 0;
}
