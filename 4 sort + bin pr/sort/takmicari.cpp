#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Ucenici{
    string ime;
    int64_t poeni;
};

bool poredi(const Ucenici &a, const Ucenici &b){
    if(a.poeni > b.poeni)
        return true;
    else if(a.poeni < b.poeni)
        return false;
    return a.ime < b.ime;
}

int main(){

    int64_t n;
    cin >> n;
    vector<Ucenici> u(n);
    for(int i=0; i<n; i++){
        cin >> u[i].ime >> u[i].poeni;
    }
    sort(begin(u),end(u),poredi);
    for(int i=0; i<n; i++){
        cout << u[i].ime << " " << u[i].poeni << endl;
    }
    return 0;
}
