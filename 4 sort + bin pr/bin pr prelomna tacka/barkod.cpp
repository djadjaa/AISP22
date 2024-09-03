#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool bin_search(vector<int64_t>& a, int64_t n, int64_t x){
    int64_t s,l=0, d=n-1;
    while(l<=d){
        s=(l+d)/2;
        if(a[s]>=x)
            d = s-1;
        else
            l = s+1;
    }
    return a[l]==x;
}

int main(){
    ios_base::sync_with_stdio(false);
    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n;  i++){
        cin >> a[i];
    }
   // sort(begin(a),end(a));
    int64_t x,num=0;
    while(cin >> x){
        if(bin_search(a,n,x))
            num++;
    }
    cout << num << endl;
    return 0;
}
