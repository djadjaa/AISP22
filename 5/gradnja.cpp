//ulica predstavljena brojevnom pravom
//uzimamo najveci razmak izmedju dve kuce
//umesto da napravimo raspored sa tacno nekim kvalitetom, mozemo napraviti raspored sa barem tim kvalitetom
//imamo linearni prolazak o(n)
//l=1, d=l[n-1]-l[0] (jer u suprotnom ako je d+=1 ispadamo iz opsega, u najboljem slucaju imacemo 2 kuce na pocetku i na kraju)
//slozenost bice o(nlog(l[n-1]-l[0]);
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool provera(int m, int n, vector<int>& lokacije,int k){ //k-> kvalitet
    int poslednjaKuca=lokacije[0];
    m--; //smanjujemo br kuca
    for(int i=1; i<n && m>0; i++){ //od druge lokacije krecemo
        if(lokacije[i]-poslednjaKuca>=k){
            poslednjaKuca = lokacije[i];
            m--;
        }
    }
    return m==0;
}

int main(){

    int n,m;//m je br kuca, n je br lokacija
    cin >> m >> n;
    vector<int> lokacije(n);
    for(int i=0; i<n; i++){
        cin >> lokacije[i];
    }
    sort(begin(lokacije), end(lokacije));
    int l=1, d=lokacije[n-1]-lokacije[0];
    int resenje=0;
    while(l<=d){
        int k=(l+d)/2; //kvalitet <=>sredina
        if(provera(m,n,lokacije,k)){
            l=k+1;
            resenje=k;
        }else{
            d=k-1;
        }
    }
    cout << resenje << '\n';
    return 0;
}
