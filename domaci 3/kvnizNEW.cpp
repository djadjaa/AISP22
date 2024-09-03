#include <bits/stdc++.h>

using namespace std;

set<int> kvadrati;
int m;

bool squareArray(vector<int>&a, int indeks){
    if(indeks == a.size()){
        return true;
    }
    if(a[indeks]!=0){
        return (kvadrati.find(a[indeks-1]+a[indeks])!=kvadrati.end()) && squareArray(a,indeks+1);
    }
    auto res = kvadrati.upper_bound(a[indeks-1]);
    while(res!=kvadrati.end()){
        a[indeks] = *res-a[indeks-1];
        if(squareArray(a,indeks+1))
            return true;
        res++;
    }
    a[indeks]=0;
    return false;
}

int main(){

    int n;
    cin >> n >> m;
    vector<int> a(n);
    int tempMax = -1;
    for(int i=0; i<n; i++){
        cin >> a[i];
        tempMax = max(tempMax,a[i]);
    }

    int x=2,y;
    while((y=x*x)<=m+tempMax){
        kvadrati.insert(y);
        x++;
    }
    if(squareArray(a,1)){
        for(int i=0; i<n; i++){
            cout << a[i] << ' ';
        }
    }else{
        cout << -1;
    }
    cout << endl;

    return 0;
}
