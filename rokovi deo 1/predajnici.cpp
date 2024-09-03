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
    sort(begin(a),end(a));
    int64_t d;
    cin >> d;
    int64_t j=0,rez=INT_MIN;
    for(int i=0; i<n; i++){
        while(a[i]-a[j]>d && j<i){
            j++;
        }
        rez=max(rez,a[i]-a[j]);
    }
    cout << rez << '\n';
    return 0;
}
