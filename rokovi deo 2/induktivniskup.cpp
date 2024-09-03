#include <bits/stdc++.h>

using namespace std;

int main(){

    int64_t n,k;
    cin >> n >> k;
    priority_queue<int64_t,vector<int64_t>,greater<int64_t>> skup;
    skup.push(n);
    while(k--){
        int64_t val = skup.top();
        skup.pop();
        cout << val << ' ';
        skup.push(2*val);
        skup.push(4*val-3);
    }
    cout << endl;

    return 0;
}
