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
    int brPr=0,x;
    while(cin >> x){
        if(binary_search(begin(a),end(a),x)){
            brPr++;
        }
    }
    cout << brPr << '\n';
    return 0;
}
