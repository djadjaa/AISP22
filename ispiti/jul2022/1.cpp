#include <bits/stdc++.h>

using namespace std;

int main(){

    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    vector<int64_t> ps(n);
    ps[0]=0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        ps[i+1] = ps[i]+a[i];
    }
    int64_t res=0;
    for(int i=0; i<n; i++){
        res += a[i+1]*ps[i+1];
    }

    cout << res << endl;


    return 0;
}
