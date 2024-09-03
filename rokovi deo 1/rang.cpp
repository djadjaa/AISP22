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
    vector<int64_t> sortiran = a;
    sort(begin(sortiran),end(sortiran));
    for(auto x:a){
        auto it = lower_bound(begin(sortiran),end(sortiran),x);
        cout << it-begin(sortiran) << ' '; //ovako dobijamo indeks
    }
    cout << '\n';
    return 0;
}
