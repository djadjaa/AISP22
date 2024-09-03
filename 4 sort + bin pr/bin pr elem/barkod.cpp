#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n;  i++){
        cin >> a[i];
    }
    int64_t x,num=0;
    while(cin >> x){
        if(binary_search(begin(a), end(a), x))
            num++;
    }
    cout << num << endl;
    return 0;
}
