#include <iostream>
#include <stack>

using namespace std;

int main(){

    int64_t k,n;
    cin >> k >> n;
    stack<int64_t> brPoj;
    stack<int64_t> elem;
    int64_t x;
    while(n--){
        cin >> x;
        if(!elem.empty() && x!=elem.top() && brPoj.top()>=k){ //ako stek nije prazan i ako x nije jednak vrhu steka a broj pojavljivanja je veci ili jednak k
            elem.pop();
            brPoj.pop();
            //tada brisemo po jedan element iz svakog steka
        }
        if(!(elem.empty()) && x==elem.top()){ //a ako je jednak uvecavamo mu br pojavljivanja
            brPoj.top()++;
        }else{ //inace je nov elem
            elem.push(x);
            brPoj.push(1);
        }
    }
    //za poslednji elem
    if(!elem.empty() && brPoj.top()>=k){
        elem.pop();
        brPoj.pop();
    }

    while (!elem.empty()) {
        cout << elem.top() << ' ';
        elem.pop();
    }

    return 0;
}
