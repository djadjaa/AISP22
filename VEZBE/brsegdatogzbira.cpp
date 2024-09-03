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
    int64_t t;
    cin >> t;
    int64_t tmpsum=0,j=0,brseg=0;
    for(int i=0; i<n; i++){
        tmpsum += a[i];
        while(tmpsum >= t){
            tmpsum -= a[j];
            j++;
        }
        brseg += i-j+1;
    }
    cout << brseg << '\n';
    return 0;
}
