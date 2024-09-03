#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){

    int n; //br zona
    cin >> n;
    vector<double> zone(n);
    for(int i=0; i<n; i++){
        cin >> zone[i];
    }
    vector<double> poluprecnik(n);
    poluprecnik[0]=zone[0];
    for(int i=1; i<n; i++){
        poluprecnik[i]=poluprecnik[i-1]+zone[i];
    }
    int m;
    cin >> m;
    while(m--){
        double x,y;
        cin >> x >> y;
        double d=sqrt(x*x+y*y); //udaljenost tacke od koordinatnog pocetka
        auto it = lower_bound(begin(poluprecnik),end(poluprecnik),d); //binarnom pretragom nalazi iterator na prvi elem >= d
        if(it==end(poluprecnik)){
            //nemamo krug koji sadrzi ovu tacku
            cout << "izvan\n";
        }else{
            //indeks = zona
            cout << it - begin(poluprecnik) << '\n';
        }
    }
    return 0;
}
//n+mlogn slozenost
//upper_bound trazi strogo veci elem od datog
