#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int main(){

    int64_t n;
    cin >> n;
    deque<int64_t> a;
    int x;
    cin >> x;
    a.push_back(x);
    for (int i = 1; i < n; i++) {
        cin >> x;
        if (a.back() < x)
            a.push_back(x);
        else
            a.push_front(x);
    }
    for(int64_t num:a){
        cout << num << ' ';
    }
    return 0;
}
