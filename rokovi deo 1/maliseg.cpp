#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int64_t t;
    cin >> t;
    int64_t br=0,j=0,z=0;
    for(int i=0; i<n; i++){
        z += a[i];
        while(z>=t){
            z -= a[j];
            j++;
        }
        br += i-j+1;
    }
    cout << br << '\n';
    return 0;
}
