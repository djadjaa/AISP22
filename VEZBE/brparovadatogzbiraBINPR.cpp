#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int64_t zbir,n;
    cin >> zbir >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(begin(a),end(a));
    int64_t brParova=0;
    for(int i=0; i<n; i++){
        int64_t aj=zbir-a[i];
        if(binary_search(begin(a),begin(a)+i,aj)){
            brParova++;
        }
    }
    cout << brParova << '\n';
    return 0;
}
