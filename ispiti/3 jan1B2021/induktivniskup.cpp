/*
 n=2, k=5
 2 4 5 8 10
 prvih k elemenata gde je prvi clan n
 x pripada tom skupu akko je 2x ili 4x-3
 n=2
 2*2
 4*2-3
 -----
 n=4
 2*4
 4*4-3
 -----
 n=5
 2*5
 4*5-3
 ------
 ...

 */
#include <iostream>
#include <queue>

using namespace std;

int main(){

    int64_t n,k;
    cin >> n >> k;
    priority_queue<int,vector<int>,greater<int> > s;
    s.push(n);
    while(k--){
        int64_t tmp = s.top();
        s.pop();
        cout << tmp << ' ';
        s.push(2*tmp);
        s.push(4*tmp-3);
    }
    cout << endl;

    return 0;
}
