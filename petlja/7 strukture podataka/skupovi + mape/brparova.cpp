/*
 7
6
2 5 4 7 0 6
(2,5) (7,0)
 */
#include <iostream>
#include <set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int64_t s,n;
    cin >> s >> n;
    set<int64_t> a;
    int64_t x,brParova=0;
    while(n--){
        cin >> x;
        if(a.find(s-x) != a.end())
            brParova++;
        a.insert(x);
    }
    cout << brParova << endl;
    return 0;
}
