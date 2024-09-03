/*
 5 11 0 0 7
 5+11=16
 11+x >=16 <=25
 ...
 */
#include <bits/stdc++.h>
using namespace std;
short m;

bool squareArray(vector<short>&a,short indeks, set<short>kvadrati){
    if(indeks == a.size()){
        return true;
    }
    if(a[indeks]!=0){ //ako je popunjeno mesto idi dalje
        return (kvadrati.find(a[indeks]+a[indeks-1])!=kvadrati.end()) && squareArray(a,indeks+1,kvadrati); //proveravamo da li se zbir dva uzastopna elementa nalazi u nizu kvadrata i idemo rekurzivno dalje
    }

    auto res = kvadrati.upper_bound(a[indeks-1]); //tražimo prvi veći od kvadrata
    while(res!=kvadrati.end()){ //sve dok se elementi nalaze u nizu
        a[indeks]=*res-a[indeks-1]; //element koji treba da smestimo u nas niz
        if(squareArray(a,indeks+1,kvadrati))
            return true;
        res++; //sledeći element
    }
    a[indeks]=0; //ostatak niza
    return false;
}
int main(){
    short n;
    cin >> n >> m;
    short maks = 0; //trebaće nam kad budemo odredili zbir dva uzastopna člana koji će biti kvadrat
    vector<short> a(n);
    for(short i=0; i<n; i++){
        cin >> a[i];
        maks = max(maks,a[i]);
    }
    set<short> kvadrati;
    short x=2,y;
    while((y=x*x)<=m+maks){
        kvadrati.insert(y);
        x++;
    }

    /*
     m=20
     5 11 0 0 7
     x=2
     y=4 <= 20+11
     y=9 <=31
     y=16 <=31
     y=25 <=31
     y=36 !<=31
     dakle zbir dva uzastopna člana mogu dati maksimalno 25 kako bi ispunilo uslov da smeštamo element do m
     */

    if(squareArray(a,1,kvadrati)){
        for(short i=0; i<n; i++){
            cout << a[i] << ' ';
        }
    }else{
        cout << -1;
    }
    cout << endl;
    return 0;
}
