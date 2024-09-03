#include <iostream>
#include <vector>

using namespace std;

void ispisi(int n, vector<int>& particije){
    for(int i=0; i<n; i++)
        cout << particije[i] << ' ';
    cout << endl;
}

void brPart(int n, int maxSab, int tempPos, vector<int>& particije){
    if(n==0){
        ispisi(tempPos,particije);
        return;
    }
    else{
        if(maxSab==0)
            return;
        brPart(n,maxSab-1,tempPos,particije); //slucaj kada na poziciji temppos smestamo sabirak za 1 manji od maksimalnog; tada dopunjujemo niz particijama broja n gde je prvi sabirak maksimalnisabirak-1
        if(maxSab<=n){
            particije[tempPos]=maxSab;
            brPart(n-maxSab,maxSab,tempPos+1,particije); //slucaj kada na poziciji temppos smestamo bas maksimalni sabirak;  kada postavimo maksimalni sabirak na toj poziciji, dopunjujemo niz od temppos+1 pozicije preostalim sabircima koji su manji ili jednaki od maksimalnog sabirka
        }
    }

    /*
    for(int sab=1; sab<=min(n,maxSab); sab++){
        particije[tempPos]=sab;
        //cout << sab << endl;
        brPart(n-sab,sab,tempPos+1,particije);
    }
    */
}

int main(){

    int n;
    cin >> n;
    vector<int> particije(n);
    brPart(n,n,0,particije);
    return 0;
}
