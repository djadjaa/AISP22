#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;
    int64_t p=1;
    for(int i=1; i<=n; i++){
        p *= i;
        cout << p << endl;
    }

    return 0;
}
