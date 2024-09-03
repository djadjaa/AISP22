#include <bits/stdc++.h>

using namespace std;

int main(){

    int64_t n;
    cin >> n;

    vector<int64_t> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    vector<int64_t> dp(n,1); //na početku imamo po 1 mogućnost za svaki član
    int64_t res=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(a[j] <= a[i]){
                dp[i] += dp[j];
                dp[i] %= (1000000007);
            }
        }
        res += dp[i];
        res %= (1000000007);
    }
    cout << res << endl;
    return 0;
}
