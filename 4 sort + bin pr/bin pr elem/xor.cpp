#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int64_t n;
    cin >> n;
    vector< int64_t> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int64_t k;
    cin >> k;

    sort(begin(a),end(a));
    int64_t numofpairs=0;
    for(int i=0; i<n; i++){
        if(binary_search(begin(a), end(a), k^a[i]))
            numofpairs++;
    }
    cout << numofpairs/2 << endl;
    return 0;
}
