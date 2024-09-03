#include <bits/stdc++.h>

using namespace std;

void stepenasti(vector<int>& a, int indeks){
    if(indeks==a.size()){
        for(int i=0; i<a.size(); i++){
            cout << a[i] << ' ';
        }
        cout << endl;
        return;
    }
    a[indeks] = a[indeks-1];
    stepenasti(a,indeks+1);
    a[indeks] = a[indeks-1]+1;
    stepenasti(a,indeks+1);
}

int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    a[0]= 1;
    stepenasti(a,1);

    return 0;
}
