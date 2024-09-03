#include <iostream>
#include <queue>
using namespace std;
int main(){
    int64_t a,b,n;
    cin >> a >> b >> n;
    /*
     * 2x i 3x
     * x=n/2
     2*1 i 3*1
     2*2 i 3*2
     2*3 i 3*3
     2*4 i 3*4
     2*5 i 3*5
     */
    priority_queue <int, vector<int>, greater<int>> sn;
    for(int i=1; i<=n/2; i++){
        sn.push(2*i);
        sn.push(3*i);
        cout << sn.top() << '\n';
    }

    return 0;
}
