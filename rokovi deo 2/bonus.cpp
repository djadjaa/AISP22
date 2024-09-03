#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int64_t n;
    cin >> n;
    int64_t k,x;
    vector<int64_t> a(n);
    multiset<pair<int64_t,int64_t>> poeni;
    for(int i=0; i<n; i++){
        cin >> a[i];
        poeni.insert({a[i],i});
    }
    cin >> k;
    for(int i=0; i<k; i++){
        cin >> x;
        int ind = poeni.begin()->second; //indeks najmanjeg
        a[ind] += x; //ažuriramo najmanji
        poeni.erase(poeni.begin()); //brišemo ga sa skupa
        poeni.insert({a[ind],ind}); //ubacujemo ažurirani sa istim tim indeksom
    }
    for(int i=0; i<n; i++)
        cout << a[i] << ' ';
    cout << endl;
    return 0;
}
