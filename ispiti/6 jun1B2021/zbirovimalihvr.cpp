/*
 potrebno je odrediti prefiksnu sumu svih elemenata koji su manji od upita
   -1 2 2 6 9
 0 1 1 3 9 18
 x=2
 upper_bound za 2 biće 6 i sabraćemo elemente do 6(ne uključujemo 6 u zbir)
 x=10
 upper_bound za 10 biće kraj niza jer ne postoji element u nizu veći od 10 pa ćemo sabrati sve elemente
 x=-5
 upper_bound za -5 biće -1 i sabraćemo sve elem do -1(ne uključujemo -1 u zbir,pa će prefiksna suma biti 0)
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int64_t n,q;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(begin(a),end(a));
    vector<int64_t> sume(n+1,0);
    partial_sum(begin(a),end(a),begin(sume)+1);
    cin >> q;
    while(q--){
        int64_t x;
        cin >> x;
        int64_t pozicija = upper_bound(begin(a),end(a),x)-begin(a);
        cout << sume[pozicija] << endl;
    }
    return 0;
}
