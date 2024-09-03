//cim procitamo segment duzine >=k brisemo ga sa steka kad dodjemo do vr razlicite od obrisane; imacemo dva steka za duzinu pojavljivanja vrednosti i stek za samu vrednost

#include <iostream>
#include <stack>
using namespace std;
int main(){
    int64_t k,n;
    cin >> k >> n;
    stack<int64_t> vr;
    stack<int64_t> brpoj;
    while(n--){
        int x;
        cin >> x;
        if(!vr.empty() && x!=vr.top() && brpoj.top()>=k){
            vr.pop();
            brpoj.pop();
        }
        if(!vr.empty() && x==vr.top()){
            brpoj.top()++;
        }else{
            vr.push(x);
            brpoj.push(1);
        }
    }
    //potrebno je proveriti da li stek nije prazan
    if(!brpoj.empty() && brpoj.top() >= k){
        vr.pop();
        brpoj.pop();
    }
    return 0;
}
/*
 push <=> push_back
 pop <=> pop_back
 top <=> back
 */
