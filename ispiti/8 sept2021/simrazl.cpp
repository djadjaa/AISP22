#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int64_t n,m;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(begin(a),end(a));
    cin >> m;
    vector<int64_t> b(m);
    for(int i=0; i<m; i++){
        cin >> b[i];
    }
    sort(begin(b),end(b));
    //primena merge sorta, ako je jedan veći od drugog i obrnuto, ispisujemo ga na standardni izlaz, inače idemo dalje
    int i=0,j=0;
    while(i<n && j<m){
        if(a[i] < b[j]){
            cout << a[i] << ' ';
            i++;
        }
        else if(b[j] < a[i]){
            cout << b[j] << ' ';
            j++;
        }
        else{
            i++;
            j++;
        }
    }
    //ispišemo ostatak niza
    while(i<n){
        cout << a[i] << ' ';
        i++;
    }
    while(j<m){
        cout << b[j] << ' ';
        j++;
    }
    cout << endl;
    return 0;
}
