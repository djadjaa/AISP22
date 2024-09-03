//3 5 8 4 2 6 9
//dva pokazivaca za kupovinu i za prodaju akcije
//kupujemo po najmanjoj, prodajemo je po najvecoj
//rekurzivno delimo niz, proveravamo maksimalnu zaradu od tih podnizova i odredjujemo maksimum
//trazimo kupovinu i prodaju levo i desno,odredjujemo maksimum a na kraju kombinaciju maksimuma
//max(zaradalevo,zaradadesno,maksimalnazaradadesno-maksimalnazaradalevo)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//[l,d) (desna granica nece biti ukljucena)
//ako imamo samo jedan elem ne mozemo nikakvu zaradu da pronadjemo
/*
int maxZarada(int l, int d, vector<int>& a){
    if(d-l<=1){
        return 0;
    }
    int s=(l+d)/2;
    int zaradaLevo = maxZarada(l,s,a);
    int zaradaDesno = maxZarada(s,d,a);
    int minLevo=*min_element(begin(a)+l,begin(a)+s);
    int maxDesno=*max_element(begin(a)+s,begin(a)+d);
    return max({zaradaLevo,zaradaDesno,maxDesno-minLevo});
}
*/

//drugi nacin
int maxZarada(int l, int d, vector<int>& a,int &minVr, int &maxVr){
    if(d-l==1){
        minVr=maxVr=a[l];
        return 0;
    }
    int s=(l+d)/2;
    int minLevo,maxLevo,minDesno,maxDesno;
    int zaradaLevo = maxZarada(l,s,a,minLevo,maxLevo);
    int zaradaDesno = maxZarada(s,d,a,minDesno,maxDesno);
    minVr=min(minLevo,minDesno);
    maxVr=max(maxLevo,maxDesno);
    return max({zaradaLevo,zaradaDesno,maxDesno-minLevo});
}
//t(n)=2t(n/2)+o(1)->o(n)

int main(){

    int n;
    cin >> n;
    vector<int> akcije(n);
    for(int i=0; i<n; i++){
        cin >> akcije[i];
    }
    int minVr,maxVr;
    cout << maxZarada(0,n,akcije,minVr,maxVr) << '\n';
    return 0;
}
//slozenost: t(n)=2*t(n/2)+o(n) -> o(nlogn) imamo n nivoa i logn koraka prema master teoremi
//pojacacemo induktivnu hipotezu tako sto cemo eliminsiati racunanje miimuma i maksimuma, za oba niza imamo zaradu  min i maks levo i analogno za desno
//trazicemo u tom slucaju minimum celog niza i maksimum celog niza
