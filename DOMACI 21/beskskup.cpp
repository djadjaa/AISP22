#include <iostream>
#include <queue>
using namespace std;

int main(){

    int64_t n,brElem;
    cin >> n >> brElem;
    priority_queue <int, vector<int>, greater<int>> sn;
    sn.push(n);
    for(int i=0; i<brElem; i++){
        int br = sn.top();
        sn.pop();
        cout << br << ' ' ;
        sn.push(2*br);
        sn.push(4*br-3);
    }
    cout << '\n';
    //2x i 4x-3
    return 0;
}
/*
 2-> 4 i 5
 4-> 8 i 13
 5-> 10 i 17
 8-> 16 i 19

 n=2
 sn.push(n) = 2
 br=sn.top() = 2
 sn.pop() = {}
 cout << 2
 sn.push(2*2) = 4
 sn.push(4*2-3) = 5
 br=sn.top() = 4
 sn.pop = {5}
 cout << 4
 sn.push(2*4) = 8
 sn.push(4*4-3) = 13
 br=sn.top() = 5
 sn.pop = {8,13}
 cout << 5
 sn.push(2*5)=10
 sn.push(4*5-3)=17
 br=sn.top()=8
 sn.pop={10,13} (jer gledamo red sa prioritetom pa samim tim se sortira
 itd itd itd
 -> 2 3 5 8 10
 */
