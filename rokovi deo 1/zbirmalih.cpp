#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for(int64_t i=0; i<n; i++){
        cin >> a[i];
    }
    sort(begin(a),end(a));

    vector<int64_t> niz_prefiksnih_suma(n+1,0); //inicijalizujemo ga nulom
    partial_sum(begin(a),end(a),begin(niz_prefiksnih_suma)+1); // pocinjemo od druge pozicije niza prefiksnih suma
    int64_t q,x;
    cin >> q;

    for(int i=0; i<q; i++){
        cin >> x;
        int poz=upper_bound(begin(a),end(a),x)-begin(a); //trazimo poziciju gde se nalazi upperbound za br x
        //cout << poz << ' ';
        cout << niz_prefiksnih_suma[poz] << '\n'; //tamo gde je upperbound tamo je i prefiksna suma do tog broja
    }
    //desice se da ne mozemo za neki broj naci upperbound pa nam u tom slucaju vraca kraj niza a potom iterator na kraj niza prefiksne sume
    /*
     * LOSA SLOZENOST
    while(q--){
        cin >> x;
        int64_t tempsum=0;
        for(int64_t i=0; i<n; i++){
            if(a[i] > x){
                break;
            }
            tempsum += a[i];
        }
        cout << tempsum << '\n';
    }
    */
    return 0;
}
