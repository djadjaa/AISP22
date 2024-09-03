#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int64_t m,x;
    cin >> m;
    while(m--){
        cin >> x;
        auto it=lower_bound(begin(a),end(a),x,greater<int>());
        cout << it-begin(a) << '\n';
    }

    return 0;
}
