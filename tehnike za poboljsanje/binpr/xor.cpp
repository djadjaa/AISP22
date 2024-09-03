#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){

    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(begin(a),end(a));
    int64_t t,brPar=0;
    cin >> t;
    for(int i=0; i<n; i++){
        if(binary_search(begin(a),end(a),t^a[i])){ //ako imamo c = a^b, a dobijamo preko c^b a b preko c^a pritom poredak je nevazan
            brPar++;
        }
    }
    cout << brPar/2 << '\n'; //delimo na dva jer trazimo broj parova
    return 0;
}
