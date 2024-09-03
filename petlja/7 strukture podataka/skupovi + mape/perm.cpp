#include <iostream>
#include <set>
using namespace std;
int main(){

    int64_t n,m;
    cin >> n;
    int64_t x;
    multiset<int64_t> a;
    while(n--){
        cin >> x;
        a.insert(x);
    }
    cin >> m;
    multiset<int64_t> b;
    while(m--){
        cin >> x;
        b.insert(x);
    }
    cout << ((a==b) ? "da\n" : "ne\n");

    return 0;
}
