#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(){

    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(begin(a),end(a),greater<int64_t>());
    int64_t minrast=INT_MAX,soba1,soba2;
    for(int i=1; i<n; i++){
        int64_t razl=a[i-1]-a[i];
        if(razl < minrast){
            minrast = razl;
            soba1 = a[i];
            soba2 = a[i-1];
        }
    }
    cout << soba1 << " " << soba2 << endl;
    return 0;
}
