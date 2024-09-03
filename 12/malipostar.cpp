/*
 nije nam dato odakle jovica krece, pa samim tim to nije ni bitno, bice u tom slucaju zbir udaljenosti jednak
 naci cemo maksimalno rastojanje tako sto cemo ici sa najdalje na najdalju koju nismo obisli, pri cemu se kuce obilaze samo 1
 biramo kucu koja maksimizuje resenje u jednom koraku, ponavljamo do poslednje obidjene kuce

 DOKAZ:
 obilazimo kuce do n
 uk udaljenost je abs(x1-x2)+abs(x2-x3)+...+abs(xn-1+xn)+abs(xn-x1)
 mora da dostigne granicu s,dakle udaljenost mora da bude <=s
 sve vr pojavice se 2 puta i imamo tacno n + i n - (prema pravilima apsolutne fje)
 u opstem slucaju prvu polovinu oduzimamo a drugu sabiramo pri cemu cemo sve ove vr sortirati kako bismo dobili manje i vece br
 dobijamo:
 ---------------- (brojevna prava)
 x1............x6
 x6-x1
 +x6-x2
 +x5-x2
 +x5-x3
 +x4-x3
 +x4-x1
 svaka vr se pojavljuje 2 puta pri cemu prve 3 su manje vr a poslednje 3 vece pa samim tim kod vr prve polovine ide - a kod druge +
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(begin(v),end(v));
    int sum=0;
    for(int i=0; i<n/2; i++){
        sum -= v[i]; //oduzimamo 1. polovinu
        sum += v[n-i-1]; //sabiramo 2. polovinu
    }
    cout << 2*sum << '\n'; //2* zbog rast
    return 0;
}
