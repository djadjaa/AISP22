#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<int>> memo;

int maxPalindrom(string &s, int l, int d){
    if(memo[l][d]!=-1){
        return memo[l][d];
    }
    if(l>d){
        return memo[l][d]=0;
    }if(l==d){
        return memo[l][d]=1;
    }
    if(s[l]==s[d]){
        return memo[l][d]=2+maxPalindrom(s,l+1,d-1);
    }
    return memo[l][d]=max(maxPalindrom(s,l+1,d),maxPalindrom(s,l,d-1));
}

int main(){

    string s;
    cin >> s;
    int n=s.size();
    memo = vector<vector<int>> (n+1,vector<int>(n+1,-1));
    cout << maxPalindrom(s,0,s.size()-1) << '\n';

    return 0;
}
