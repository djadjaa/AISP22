#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int64_t n,t;
    cin >> n >> t;
    int64_t x;
    string s;
    map<int64_t,int64_t> numOcc;
    int64_t numPair=0;
    while(n--){
        cin >> s;
        if(s== "pisi"){
            //ubacujemo element
            cin >> x;
            numPair += numOcc[t-x];
            numOcc[x]++;
        }
        else if(s=="brisi"){
            cin >> x;
            numOcc[x]--;
            numPair -= numOcc[t-x];
        }
        else{
            cout << numPair << endl;
        }
        for(auto it = numOcc.begin(); it != numOcc.end(); it++)
            cout << "BR POJ: " << it-> first << ' ' << it->second << endl;
        cout << "trenutni br parova: " << numPair << endl;
    }
    return 0;
}
/*
 10 6
pisi 4
10 6
pisi 4
BR POJ: 2 0 [t-x]
BR POJ: 4 1
pisi 2
BR POJ: 2 1
BR POJ: 4 1
upit
1
BR POJ: 2 1
BR POJ: 4 1
pisi 2
BR POJ: 2 2
BR POJ: 4 1
upit
2
BR POJ: 2 2
BR POJ: 4 1
pisi 3
BR POJ: 2 2
BR POJ: 3 1
BR POJ: 4 1
pisi 3
BR POJ: 2 2
BR POJ: 3 2
BR POJ: 4 1
upit
5

to je jer je redosled instrukcija sledeci:
numOcc[x]++;
numPair += numOcc[t-x];

naime, moze se desiti da element sam sa sobom daje rezultat
izracunace se najpre br pojavljivanja pojavljivanja pa će se izracunati neverodostojno br parova
zato mora obrnuto
 */
