#include <bits/stdc++.h>

using namespace std;

int main(){

    int64_t n,m,s;
    cin >> n >> m >> s;
    vector<vector<int64_t>> dp(n+1,vector<int64_t>(s+1,0));
    dp[0][0] = 1;
    for(int i=1; i<=n; i++){ //br kockica
        for(int j=0; j<=s; j++){ //do koliko sabiramo
            for(int k=1; k<=m; k++){ //koliko strana ima kockica
                if(k<=j) //brojevi sa strane kockica moraju biti manje od zbira kako bismo dobili verodostojnije rešenje
                    dp[i][j] = (dp[i][j]+dp[i-1][j-k])%(1000000007); //za jednu kockicu uzimamo jedan broj od 1 do m, a za drugu (preostalu) uzimamo broj s-m kako bismo dobili željeni zbir
            }
        }
    }
    cout << dp[n][s] << endl;
    return 0;
}
