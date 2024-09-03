/*
 kada imamo igraca na koordinatnom pocetku, on na raspolaganju ima ceo poluprečnik
 npr: igrac-0, d=1, r=5
 poluprečnik će se smanjivati za d sve dok ne bude 0, u tom slucaju pošto računamo i ivicu poluprečnika biće minutaža 6
 međutim ako imamo igrača koji nije na koordinatnom poč. (recimo 1)
 igrač-1
 poluprečnik je za 1 manji jer se na koordinati 1,0 nalazi igrač, pa će se preostali poluprečnik standardno smanjiti pa će minutaža biti 5
 stoga će minutaža biti (poluprečnik-igrač)/d+1
 brojilac: (poluprečnik-igrač) - objasnili smo da je poluprečnik manji kad je igrač van koordinatnog
 imenilac: d - prostor na raspolaganju će se svakog minuta smanjiti za d
 +1 - računamo ivice intervala prostora
 */
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int64_t n,d,r;
    cin >> n >> r >> d;
    while(n--){
        int64_t x,minutaza;
        cin >> x;
        x=abs(x);
        if((r-x)<0){
            cout << 0 << endl;
        }else{
            cout << ((r-x)/d)+1 << endl;
        }
    }
    return 0;
}
