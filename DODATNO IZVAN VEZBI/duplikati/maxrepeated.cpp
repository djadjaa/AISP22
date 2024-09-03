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
    int64_t num=1,rez;
    for(int i=1; i<n; i++){
        if(a[i-1]==a[i]){
            num++;
            rez = a[i];
        }
    }
    if(num >= 2){
        cout << rez << endl;
    }else{
        cout << "nema\n";
    }
    return 0;
}
