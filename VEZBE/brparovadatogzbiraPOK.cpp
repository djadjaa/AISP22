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
    int64_t i=0,j=n-1;
    while(i<j){
        if(a[i]+a[j]==zbir){
            brParova++;
            i++;
            j--;
        }else if(a[i]+a[j]>zbir){
            j--;
        }else{
            i++;
        }
    }
    cout << brParova << '\n';
    return 0;
}
