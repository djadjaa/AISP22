//a1+a2+a3=0; a1=-(a2+a3), fiksiramo 2 vr da bismo dobili trecu; mora da vazi uslov i<j<k;
//gledacemo jti i kti elem, trazimo iti koji je levo od jtog i ktog, pomeramo kti elem sve do kraja -> slozenost bice O(n^2logn)
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main(){

    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int64_t num3sum=0;
    set<int>vr;
    for(int j=0; j<n; j++){
        for(int k=j+1; k<n; k++){
            if(vr.find(-(a[j]+a[k]))!=vr.end())
                num3sum++;
        }
        vr.insert(a[j]);
    }
    cout << num3sum << endl;
    return 0;
}
