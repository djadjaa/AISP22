#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

bool poznajeNekoga(const vector<vector<bool>>& poznaje, int i){
    int n=poznaje.size();
    for(int j=0; j<n; j++){
        if(j!=i && poznaje[i][j]) //ako osoba i poznaje osobu j vraćamo true; u mainu je poenta da proverimo da li NE VAŽI da potencijalna zvezda poznaje osobu j
            return true;
    }
    return false;
}

bool sviJePoznaju(const vector<vector<bool>>& poznaje, int i){
    int n=poznaje.size();
    for(int j=0; j<n; j++){
        if(j!=i && !poznaje[j][i]) //ako ne važi da osoba j poznaje osobu i, a pritom je i potencijalna zvezda, vraćamo false; OVO JE OKEJ što se vraća false zato što svi moraju da poznaju potencijalnu zvezdu, odnosno svaka osoba j
            return false;
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    vector<vector<bool>> poznaje(n,vector<bool>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> poznaje[i][j];
        }
    }
    int i=0;
    for(int j=1; j<n; j++){
        if(poznaje[i][j]) //ako i poznaje j, i nije zvezda, pa i postaje j odn tekuća osoba (jer osobe posle osobe i analiziramo), a j standardno ide dalje; u suprotnom, i je kandidat a j nije jer ne poznaje zvezdu a zvezdu moraju svi da poznaju, pa se j standardno uvećava što ne moramo pisati jer se j inkrementira u petlji
            i=j; //novi kandidat (i) je j
    }
    int kandidat = i;
    int zvezda = -1;
    if(sviJePoznaju(poznaje,kandidat) && !poznajeNekoga(poznaje,kandidat)) //poredimo kandidata (i) sa svim elementima kolone
        zvezda = kandidat;

    cout << zvezda << endl;
    return 0;
}
