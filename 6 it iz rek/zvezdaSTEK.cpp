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
    stack <int> s;
    for(int i=0; i<n; i++){
        s.push(i);
    }
    while(s.size() > 1){
        int a = s.top();
        s.pop();
        int b= s.top();
        s.pop();
        if(poznaje[a][b]) //ako a poznaje b (ako je vrednost true), tada je kandidat za zvezdu b, zato što da bi bio zvezda, ne bi trebalo nikog da poznaješ pa a nije kandidat
            s.push(b);
        else //obratna situacija
            s.push(a);
    }
    //rešenje je jednočlan stek
    int kandidat = s.top();
    int zvezda = -1;
    if(sviJePoznaju(poznaje,kandidat) && !poznajeNekoga(poznaje,kandidat)) //poredimo kandidata (i) sa svim elementima kolone
        zvezda = kandidat;

    cout << zvezda << endl;
    return 0;
}
