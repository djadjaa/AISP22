#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main(){

    int64_t n;
    cin >> n;
    set<int64_t> duples;
    int64_t x,maks=0;
    while(n--){
        cin>> x;
        if(duples.find(x) != duples.end())
            maks = max(maks,x);
        duples.insert(x);
    }
    cout << maks << endl;
    return 0;
}
