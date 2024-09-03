#include <iostream>
#include <climits>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int64_t n;
    cin >> n;
    int64_t max=INT_MIN,x;
    while(n--){
        cin >> x;
        if(x>max)
            max=x;
        cout << max << endl;
    }
    return 0;
}
