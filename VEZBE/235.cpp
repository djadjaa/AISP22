#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(){

    int64_t n;
    cin >> n;
    queue<int64_t> dvojke;
    queue<int64_t> trojke;
    queue<int64_t> petice;
    dvojke.push(2);
    trojke.push(3);
    petice.push(5);
    int64_t t=1;
    while(n--){
        t=min({dvojke.front(),trojke.front(),petice.front()});
        if(dvojke.front()==t){
            dvojke.pop();
        }
        if(trojke.front()==t){
            trojke.pop();
        }
        if(petice.front()==t){
            petice.pop();
        }
        dvojke.push(2*t);
        trojke.push(3*t);
        petice.push(5*t);
    }
    cout << t << '\n';
    return 0;
}
