#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){

    int64_t n,k;
    cin >> n >> k;
    int64_t x;
    priority_queue<int64_t, vector<int64_t>, greater<int64_t> > najK;
    for(int i=0; i<k; i++){
        cin >> x;
        najK.push(x);
    }
    for(int i=k; i<n; i++){
        cin >> x;
        if(x > najK.top()){
            najK.pop();
            najK.push(x);
        }
    }
    int64_t sum=0;
    for(int i=0; i<k; i++){
        int64_t tmp = najK.top();
        sum += tmp;
        najK.pop();
    }
    cout << sum << endl;
    return 0;
}
