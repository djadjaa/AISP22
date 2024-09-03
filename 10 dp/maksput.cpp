#include <bits/stdc++.h>

using namespace std;
/*
int maxPath(vector<vector<int>>& a, int v, int k, int n){
    if(v==0 && k==0)
        return a[v][k];
    int dole, desno;
    if(v>0)
        dole = a[v][k] + maxPath(a,v-1,k,n);
    if(k>0)
        desno = a[v][k] + maxPath(a,v,k-1,n);
    if(v==0) //ako smo stigli do kraja vrste biće rešenje skroz desno
        return desno;
    if(k==0) //ako smo stigli do kraja kolone biće rešenje skroz dole
        return dole;
    return max(dole,desno);
}
*/


int maxPath(vector<vector<int>>& a, int v, int k, int n,vector<vector<int>>& memo){
    if(memo[v][k]!=-1)
        return memo[v][k]; //ovo radimo da bismo sprečili ponovljene rekurzivne pozive
    if(v==0 && k==0)
        return memo[v][k] = a[v][k];
    int dole, desno;
    if(v>0)
        dole = a[v][k] + maxPath(a,v-1,k,n,memo);
    if(k>0)
        desno = a[v][k] + maxPath(a,v,k-1,n,memo);
    if(v==0) //ako smo stigli do kraja vrste biće rešenje skroz desno
        return memo[v][k] = desno;
    if(k==0) //ako smo stigli do kraja kolone biće rešenje skroz dole
        return memo[v][k] = dole;
    return memo[v][k] = max(dole,desno);
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
    vector <vector<int>> memo(n,vector<int>(n,-1));
    cout << maxPath(a,n-1,n-1,n,memo) << endl;
    return 0;
}
