#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Ocene{
    vector<int64_t> ocene;
    int64_t uk;
    double prosek;
};

bool poredi(const Ocene &a, const Ocene &b){
    if(a.prosek > b.prosek)
        return true;
    else
        return false;
}

int main(){

    int64_t u,o;
    cin >> u >> o;
    vector<Ocene> a(u);
    for(int i=0; i<u; i++){
        a[i].ocene.resize(o+1);
        a[i].uk = 0;
        for(int j=0; j<o; j++){
            cin >> a[i].ocene[j];
            a[i].uk += a[i].ocene[j];
        }
    }
    for(int i=0; i<u; i++){
        a[i].prosek = (double)a[i].uk/o;
    }
    //sort(begin(a),end(a),poredi);
    stable_sort(begin(a),end(a),poredi);
    for(int i=0; i<u; i++){
        for(int j=0; j<o; j++){
            cout << a[i].ocene[j] << " ";
        }
        cout << '\n';
    }
    return 0;
}
