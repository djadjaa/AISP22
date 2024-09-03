/*
 uslov je da SVI segmenti duzine k daju zbir >= t i da je to k najmanje moguce
plus da su svi elementi uzastopni

 npr
 3 1 2 1 5 2
 k = 3 samo ako 1+2+3 i 1+2+2 ali 1+2+1 ne daju zbir >= t
 k=4 bi vec moglo jer:
 3+1+2+1
 1+1+2+2
 2+2+3+5
 itd
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool foo(vector<int64_t>& a, int k, int64_t t){
    int64_t sum=0;
    for(int i=0; i<a.size(); i++){
        sum += a[i];
        if(i>=k-1){
            if(sum<t){
                return false;
            }
            sum -= a[i-k+1];
        }
    }
    return true;
}

int main(){

    int64_t n,t;
    cin >> n >> t;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    sort(begin(a),end(a)); //u pitanju su uzastopni brojevi
    int l=0, d=n-1;
    //s ce nam predstaviti granicu do koje ce ici zbir odn pokazivaci
    while(l<=d){
        int s=l+(d-l)/2;
        if(foo(a,s,t))
            d = s-1;
        else
            l = s+1;
    }
    if(l==n) //ako smo stigli do kraja a nismo nasli zeljeni rezultat
        cout << 0 << endl;
    else
        cout << l << endl;
    return 0;
}
