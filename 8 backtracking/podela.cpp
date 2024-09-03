#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

double podele(vector<double>&p, double z1, double z2, int nivo){
    if(nivo==p.size()){
        return abs(z1-z2);
    }
    double levoPodstablo=podele(p,z1+p[nivo],z2,nivo+1);
    double desnoPodstablo=podele(p,z1,z2+p[nivo],nivo+1);
    return min(levoPodstablo,desnoPodstablo); //listovi levog i desnog podstabla cuvaju najmanji zbir: onaj koji ima manji, prelazimo na to podstablo i racunamo dalje najmanju razliku izmedju dva zbira u podstablu
}

int main(){
    int n;
    cin >> n;
    vector<double>p(n);
    for(int i=0; i<n; i++){
        cin >> p[i];
    }
    cout << fixed << setprecision(2) << podele(p,0,0,0) << '\n';
    return 0;;
}
