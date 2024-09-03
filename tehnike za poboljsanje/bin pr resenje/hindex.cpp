#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rezultat(vector<int64_t>&a, int n){
    int l=0, d=n-1;
    while(l<=d){
        int64_t s=l+(d-l)/2;
        //kada su l,d i s jednaki to ce nam biti resenje
        if(a[s]==n-s){
            return a[s];
        }else if(a[s]>n-s){
            d=s-1;
        }else{
            l=s+1;
        }
    }
    return n-l;
}

int main(){

    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(begin(a),end(a));
    cout << rezultat(a,n) << '\n';
    return 0;
}
/*
 * 0 1 2 3 7 8
 s=2
 a[s]=6-2 -> 2=4 ? -> manje je tako da je l=3
 s=4
 a[s]=6-4 -> 3=4 ? -> manje je tako da je l=5
 s=5
 a[s]=6-7 -> -1=4 -> manje je tako da je l=6
 posto je l=6 a d=5 petlja se zaustavlja
 dobijamo...
  */
