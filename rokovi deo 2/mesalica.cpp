/*
koristićemo mapu gde je ključ broj a vrednost indeks

4 3 1 0 2

za prvi niz imamo mapu:
[{4,0},{3,1},{1,2},{0,3},{2,3}]
--------------------------------------
1 3 2 4 0

ovde ćemo napraviti niz m na osnovu ovih brojeva, gde ce indeksi niza biti vrednosti mape, a vrednosti niza su brojaci koji idu redom (zato što ćemo ih koristiti za mešanje)

1 = m[poz[x]] = i => m[poz[1]] = m[2] =  0

dobićemo:
3 1 0 4 2
--------------------------------------
3 2 0 4 1

ovde ćemo napraviti niz b na osnovu ovih brojeva gde će indeksi biti vrednosti prethodnog niza,a vrednosti niza baš ovi dati brojevi (zato što je to krajnji niz)

3 = b[m[i]] = x => b[m[0]] = b[3] = 3

dobićemo:
0 2 1 3 4

 */

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    unordered_map<int,int> pozicije;
    int x;
    for(int i=0; i<n; i++){
        cin >> x;
        pozicije[x] = i;
    }
    vector<int> m(n);
    for(int i=0; i<n; i++){
        cin >> x;
        m[pozicije[x]] = i;
    }
    vector<int> b(n);
    for(int i=0; i<n; i++){
        cin >> x;
        b[m[i]]=x;
    }
    for(int i=0; i<n; i++)
        cout << b[i] << ' ';
    cout << endl;

    return 0;
}
