#include <bits/stdc++.h>

using namespace std;

void findMatrSum(vector<vector<int>> a, int v, int k, int n, int sum, set<int>&sume){
    sum += a[v][k];
    if(v==n-1 && k==n-1){
        sume.insert(sum);
        return;
    }
    if(k+1<n){
        findMatrSum(a,v,k+1,n,sum,sume);
    }
    else if(v+1<n){
        findMatrSum(a,v+1,k,n,sum,sume);
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
    set<int> sume;
    findMatrSum(a,0,0,n,0,sume);
    for(auto s:sume){
        cout << s << ' ';
    }
    /*
    vector<vector<int>> memo(n,vector<int>(n));
    memo[0][0] = a[0][0];
    for(int v=1; v<n; v++)
        memo[v][0] = memo[v-1][0] + a[v][0];
    for(int k=1; k<n; k++)
        memo[0][k] = memo[0][k-1] + a[0][k];
    for(int v=1; v<n; v++){
        for(int k=1; k<n; k++){
            memo[v][k] = max(memo[v-1][k] + a[v][k], memo[v][k-1] + a[v][k]);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << memo[i][j] << ' ';
        }
        cout << endl;
    }
    */
    return 0;
}
