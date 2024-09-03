/*
 za svaku desnu poziciju odredjujemo najdalju poziciju od njega do leve pozicije
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
    //i je levi j je desni pokazivač
    int64_t i=0,maxRazdaljina=0;
    for(int j=1; j<n; j++){
        while(a[j]-a[i]>d && i<j){ //kada bude prestalo da važi da rastojanje između levog i desnog predajnika <= d tada pomeramo levi pokazivač
            i++;
        }
        maxRazdaljina = max(maxRazdaljina,a[j]-a[i]);
    }
    cout << maxRazdaljina << endl;
    return 0;
}
