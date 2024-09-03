#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(begin(a),end(a));
    int64_t t;
    cin >> t;
    int64_t brParova=0;
    for(int i=0; i<n; i++){
        if(binary_search(begin(a),end(a),a[i]^t)){
            brParova++;
        }
    }
    cout << brParova/2 << '\n';
    return 0;
}
