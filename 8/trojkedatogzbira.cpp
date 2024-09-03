//a1+a2+a3=0; a1=-(a2+a3), fiksiramo 2 vr da bismo dobili trecu; mora da vazi uslov i<j<k; gledacemo jti i kti elem, trazimo iti koji je levo od jtog i ktog, pomeramo kti elem sve do kraja -> slozenost bice O(n^2logn)
#include <iostream>
#include <set>
#include <vector> //u prethodnom zadatku nismo morali da pamtimo niz jer smo samo unosili i odmah proveravali, u ovom slucaju pamtimo pozicije elemenata i idemo redom i proveravamo trojke
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    set<int> vrednosti; //one su sa leve str u odnosu na pokazivac j
    int brTrojki=0;
    for(int j=0; j<n; j++){
        for(int k=j+1; k<n; k++){
            if(vrednosti.find(-(a[j]+a[k])) != end(vrednosti)){
                brTrojki++;
            }
        }
        vrednosti.insert(a[j]);
    }
    cout << brTrojki << '\n';
    return 0;
}
