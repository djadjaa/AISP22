/*
 maksimalna dubina podmornice ne sme da prekorači p
 stoga je formula x-hi<=p pri čemu primenjujemo inkrementalnost -> prefiksne sume visina
 radimo njih zato što se uk pritisak računa kao zbir pritiska na svaki segment podmornice
 od svih maksimalnih dubina biramo najmanju
 */

#include <bits/stdc++.h>

using namespace std;

int main(){

    int64_t sirina, granica;
    cin >> sirina >> granica;
    vector<int64_t> h(sirina);
    for(int i=0; i<sirina; i++)
        cin >> h[i];
    sort(begin(h),end(h));
    vector<int64_t> ps(sirina+1);
    partial_sum(begin(h),end(h),begin(ps));
    int64_t minDubina = INT64_MAX;
    for(int i=0; i<sirina; i++){
        int64_t tmpdubina = (granica + ps[i])/(i+1);
        if(tmpdubina<minDubina){
            minDubina=tmpdubina;
        }
    }
    cout << minDubina << endl;

    return 0;
}
