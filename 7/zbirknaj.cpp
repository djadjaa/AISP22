/*
 kod reda sa prioritetom uzastopni push i pop dace slozenost o(logn)
 ovde biramo prvih k elemenata, trazimo minimum koji uklanjamo iz reda i ubacujemo veci od njega i tako sve dok ne nadjemo top 3 najbolja uradjena zadatka
 prostorna je o(k) jer cuvamo samo k elemenata (u redu)
 vremenska o(nlogk) jer imamo k elemenata u skupu i uzastopno radimo push i pop (top nece uticati)
 */
#include <iostream>
#include <queue>
using namespace std;
int main(){

    int n,k,x;
    cin >> n >> k;
    priority_queue<int, vector<int>, greater<int> > najvecihK; //greater znaci da znak manje znaci vece
    for(int i=0; i<k; i++){
        cin >> x;
        najvecihK.push(x);
    }
    for(int i=k; i<n; i++){
        cin >> x;
        if(x>najvecihK.top()){
            najvecihK.pop();
            najvecihK.push(x);
        }
    }
    int64_t zbir=0;
    while(!najvecihK.empty()){
        zbir += najvecihK.top();
        najvecihK.pop();
    }
    cout << zbir << '\n';
    return 0;
}
