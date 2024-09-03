#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int64_t n;
    cin >> n;
    vector <int64_t> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(begin(a),end(a));
    for(int i=0; i<n; i+=2){
        if(a[i]!=a[i+1]){
            cout << a[i] << endl;
            break;
        }
    }
    return 0;
}
