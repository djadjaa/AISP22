#include <iostream>
#include <stack>

using namespace std;

int main(){

    int64_t k,n;
    cin >> k >> n;
    stack<int64_t> a;
    stack<int64_t> numOcc;
    int64_t x;
    for(int i=0; i<n; i++){
        cin >> x;
        if(!a.empty() && x!=a.top() && numOcc.top()>=k){ //ako x nije jednak tekućem elem na vrhu steka i njegov br pojavljivanja prestiže k brišemo ga
            a.pop();
            numOcc.pop();
        }
        if(!a.empty() && x==a.top()){ //ako je jednak, uvećavamo mu br pojavljivanja
            numOcc.top()++;
        }
        else{
            a.push(x);
            numOcc.push(1);
        }
    }
    if(!a.empty() &&  numOcc.top()>=k){
        a.pop();
        numOcc.pop();
    }

    for (stack<int64_t> dump=a; !dump.empty(); dump.pop())
        cout << dump.top() << ' ';
    cout << endl;
    return 0;
}
