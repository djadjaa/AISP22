#include <iostream>
#include <iomanip>
using namespace std;

int64_t gaus(int n){
    return (n*(n+1))/2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a,d,n;
    double rez;
    cin >> n;
    while(cin >> a >> d){
        rez = n*a+d*gaus(n-1);
        rez /= 1000;
        cout << fixed << setprecision(2) << showpoint << rez <<'\n';
    }

    return 0;
}
/*
 metre n puta sabiramo, pri čemu će se d inkrementalno uvećati za 1 pa za 2 itd sve do brdana-1 (pošto se prvog dana vrednost metara ne menja)
 */
