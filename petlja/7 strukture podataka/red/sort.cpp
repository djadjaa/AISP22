#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int64_t n;
    cin >> n;
    deque<int64_t> a;
    int64_t x;
    cin >> x;
    a.push_back(x);
    n--;
    while(n--){
        cin >> x;
        if(x > a.back()){
            a.push_back(x);
        }else{
            a.push_front(x);
        }
    }

    return 0;
}
