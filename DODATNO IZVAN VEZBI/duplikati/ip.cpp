#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    int64_t n;
    cin >> n;
    vector <int64_t> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(begin(a),end(a));
    int64_t num=1; //barem jedan različit
    for(int i=1; i<n; i++){
        if(a[i-1]!=a[i]){
            num++;
        }
    }
    cout << num << endl;
    return 0;
}
