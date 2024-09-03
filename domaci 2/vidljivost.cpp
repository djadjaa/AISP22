#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int64_t n,k;
    cin >> n >> k;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    multiset<int64_t> sedista;
    int j=0;
    for(int i=0; i<n; i++){
        if(sedista.size()>k) //posmatramo k sedista
            sedista.erase(sedista.find(a[j++]));

        if(sedista.lower_bound(a[i])!=sedista.end()){
            cout << "1 ";
        }else{
            cout << "0 ";
        }

        sedista.insert(a[i]);
    }

    return 0;
}
