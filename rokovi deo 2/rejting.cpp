#include <bits/stdc++.h>
using namespace std;
int main(){

    ios_base::sync_with_stdio(false);
    //kako učitavamo brojeve automatski se ispisuju na standardni izlaz pa je neophodno ovo napisati
    int64_t n,k;
    cin >> k >> n;
    int64_t x;
    priority_queue <int64_t,deque<int64_t>> takm;
    for(int i=0; i<n; i++){
        cin >> x;
        if(i<k){
            cout << 0 << ' ';
            takm.push(x);
        }
        else if(x<=takm.top()){
            takm.pop();
            takm.push(x);
            cout << 0 << ' ';
        }
        else if(x>takm.top())
            cout << 1 << ' ';
    }
    cout << endl;
    return 0;
}
/*
 2 5 3 6 3 4

 2 -> 0 jer nema nikog ispred njega (queue: 2)
 5 -> 0 jer ima samo 1 manji ispred njega (2,5)
 3 -> 0 - || - (2,3,5) (posto se trazi bar k, a k nam je 2, brisemo jedan od elemenata:-> 2,3)
 6 -> 1 - jer 2,3 < 6
 3 -> 0 - jer imamo samo 1 ispred njega koji je manji a to je 2 (2,3,3, ali posto se trazi bar k, brisemo jedan elem:-> 2,3)
 4 -> 1 - jer 2,3 < 4

 */
