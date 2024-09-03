#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Ucenik{
    string ime,prezime;
};

bool poredi(const Ucenik &a, const Ucenik &b){
    if(a.ime < b.ime){
        return true;
    }else if(a.ime > b.ime){
        return false;
    }
    return a.prezime < b.prezime;
}

int main(){
    ios_base::sync_with_stdio(false);
    vector<Ucenik> u;
    string s;
    int bru=0;
    while(getline(cin,s)){ //getline zbog parsiranja linije
        int parse = s.find(' ');
        string ime = s.substr(0,parse);
        string prezime = s.substr(parse+1);
        u.push_back({ime,prezime});
        bru++;
    }
    sort(begin(u),end(u),poredi);
    /*
    for(int i=0; i<bru; i++)
        cout << u[i].ime << " " << u[i].prezime << endl;
    */

    for(int i=1; i<bru; i++){
        if(u[i].ime == u[i-1].ime && u[i].prezime == u[i-1].prezime){
            cout << u[i].ime << " " << u[i].prezime << endl;
            break;
        }
    }

    return 0;
}
