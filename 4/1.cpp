#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Takmicar{
    string ime;
    int bodovi;
};
// vracamo true ukoliko a treba da se nadje ispred b u nizu nakon sortiranja a inace false
bool poredi(Takmicar a, Takmicar b){
    if(a.bodovi > b.bodovi){
        return true;
    }if(a.bodovi < b.bodovi){
        return false;
    }
    return a.ime < b.ime; //leksikografski poredak ako su bodovi jednaki
}

int main(){

    int n,i;
    cin >> n;

    vector<Takmicar> takmicari(n);
    for(int i=0; i<n; i++){
        cin >> takmicari[i].ime >> takmicari[i].bodovi;
    }
    //pocetni i krajnji iterator + fj poredjenja
    sort(begin(takmicari),end(takmicari),poredi);
    for(auto t:takmicari)
        cout << t.ime << ' ' << t.bodovi << '\n';

    return 0;
}

/*ili
 sort(begin(takmicari),end(takmicari),[](Takmicar a, Takmicar b){
    if(a.bodovi > b.bodovi){
        return true;
    }if(a.bodovi < b.bodovi){
        return false;
    }
    return a.ime < b.ime; */
