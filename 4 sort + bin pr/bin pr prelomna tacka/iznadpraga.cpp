#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //upper bound veci od trenutnog elementa upper_bound(5)=6
    //lower bound manji od najveceg lower_bound(5)=4 (pod uslovom da 4 i 6 pripadaju skupu)
    int64_t n,m;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int64_t x; //prag
    cin >> m;
    while(m--){
        cin >> x;
        auto it = upper_bound(begin(a),end(a),x,greater<int64_t>());
        cout << it - begin(a) << '\n';
    }

    return 0;
}
