#include <bits/stdc++.h>

using namespace std;

void maxPath(vector<vector<int>>& memo, int v, int k){
    if(v==0 && k==0)
        return;
    if(v==0){ //prva vrsta -> idemo levo od tih elemenata
        maxPath(memo,v,k-1);
        cout << "desno\n";
    }
    else if(k==0){ //prva kolona -> idemo odozdo ka gore
        maxPath(memo,v-1,k);
        cout << "dole\n";
    }
    else if(memo[v-1][k] > memo[v][k-1]){ //je l bolje ici dole ili desno
        maxPath(memo,v-1,k);
        cout << "dole\n";
    }else{
        maxPath(memo,v,k-1);
        cout << "desno\n";
    }
}

int main(){

    int n;
    cin >> n;
    vector<vector<int>> a(n,vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }
    vector<vector<int>> memo(n,vector<int>(n));
    memo[0][0] = a[0][0];
    //nulta vrsta
    for(int v=1; v<n; v++)
        memo[v][0] = memo[v-1][0] + a[v][0];
    //nulta kolona
    for(int k=1; k<n; k++)
        memo[0][k] = memo[0][k-1] + a[0][k];
    for(int v=1; v<n; v++){
        for(int k=1; k<n; k++){
            memo[v][k] = max(memo[v-1][k]+a[v][k], memo[v][k-1]+a[v][k]);
        }
    }
    cout << memo[n-1][n-1] << endl;
    maxPath(memo,n-1,n-1);
    return 0;
}
