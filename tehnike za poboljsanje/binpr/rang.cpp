#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Studenti{
    string ime;
    int poeni,plasman;
};

bool poredi(const Studenti& a, const Studenti& b){
    if(a.poeni > b.poeni){
        return true;
    }else{
        return false;
    }
}

int main(){

    int n;
    cin >> n;
    vector<Studenti> st(n);
    vector<int> ogPoz(n);
    for(int i=0; i<n; i++){
        cin >> st[i].ime >> st[i].poeni;
        ogPoz.push_back(i+1);
    }
    sort(begin(st),end(st),poredi);

//TODO

    return 0;
}
