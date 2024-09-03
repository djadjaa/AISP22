#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Takmicar{
    string ime;
    int bodovi;
    bool operator<(Takmicar b){ //izdvajamo takmicara i poredimo u opstem smislu
        if(bodovi > b.bodovi)
            return true;
        if(bodovi < b.bodovi)
            return false;
        return ime < b.ime;
    }
};

int main(){

    int n,i;
    cin >> n;

    vector<Takmicar> takmicari(n);
    for(int i=0; i<n; i++){
        cin >> takmicari[i].ime >> takmicari[i].bodovi;
    }
    //pocetni i krajnji iterator + fj poredjenja koja se nalazi u strukturi
    sort(begin(takmicari),end(takmicari));
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
