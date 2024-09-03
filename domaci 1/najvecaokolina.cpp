/*
 posmatraćemo d sa leve i d sa desne strane:
 ----(---*---)---- <- okolina tačke * (zato posmatramo i levu i desnu str)
 potrebno je proveriti da li element formira najveću okolinu
 imaćemo levu i desnu granicu, gde će leva ići do d, a desna do kraja niza.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int64_t n,d;
    cin >> n >> d;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(begin(a),end(a));
    int64_t lg=0,dg=0,maxOkolina=0,element=0;
    for(int i=0; i<n; i++){ //prolazimo kroz sve elemente niza
        while(a[dg]<=a[i]+d && dg<n){ //posmatramo desni deo od d, sve dok ne iskočimo iz okoline
            dg++;
        }
        while(a[lg]<a[i]-d && lg<d){ //isto i za levo od d
            lg++;
        }
        //u pitanju su uslovi a[i]-d i a[i]+d zato što okolina neke tačke je upravo definisana na takav način: (*-d,*+d)
        //naravno uslovi su i lg<d i dg<n jer je u pitanju otvoreni interval
        if(dg-lg > maxOkolina){
            maxOkolina = dg-lg;
            element = i;
        }
    }
    cout << a[element] << ' ' << maxOkolina << endl;

    return 0;
}
