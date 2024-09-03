#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main(){

    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        a[i] -= i;
    }
    auto it=lower_bound(begin(a),end(a),0); //a[i]-i==0 -> u tom slucaju nasli smo a[i]=i;
    if(it!=a.end() && *it==0){
        cout << distance(begin(a),it) << '\n'; //distance racuna koliko je udaljen nas iterator tj resenje koje smo nasli od pocetka niza; u tom slucaju nasli smo indeks trazenog elementa;
    }else{
        cout << "nema\n";
    }
    return 0;
}
