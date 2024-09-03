#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int64_t sum,n;
    cin >> sum >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(begin(a),end(a));
    int64_t numofpairs=0;
    for(int i=0; i<n; i++){
        if(binary_search(begin(a), begin(a)+i, sum-a[i]))
            numofpairs++;
    }
    cout << numofpairs << endl;
    return 0;
}
