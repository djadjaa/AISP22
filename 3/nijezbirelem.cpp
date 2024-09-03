#include <iostream>
#include <vector>
using namespace std;
int main(){

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    //sort(begin(a),end(a));
    int zbir=0;
    for(int i=0; i<n; i++){
        if(a[i]>zbir+1){ //ako nemamo presek prekidamo petlju
            break;
        }
        zbir += a[i];
    }
    cout << zbir+1 << '\n';
    return 0;
}
