/*
 * [0,4256]
 * => [0,999]U[1000,1999]U[2000,2999]U[3000,3999]U[4000,4256]
 * => najpre proveravamo koliko elem ima svaki interval
 * f(999)+f(999)+f(999)+ne gledamo jer sigurno ima trojku u br => 0 +f(256) ===> 3f(999)+f(256)
 *
 * f(999) = [0,99]U...U[900,999] (bez [300,399])
 * => 9*f(99)
 * f(99) = [0,9]U...U[90,99] (bez [30,39])
 *=> 9*f(9)
 * f(9) = 9
 * f(99) = 81
 * f(999) = 9*81=729
 *
 * f(256) = [0,99]U[100,199]U[200,256] => 2*f(99)+f(56)
 * f(56) = [0,9]U[10,19]U[20,29]U[90,99]U[90,99]U[90,99]
*/

#include <iostream>
#include <string>
using namespace std;

int f(string n){
    if(n=="")
        return 1;
    int c=n[0]-'0';
    string devetke = string(n.size()-1,'9'); //što je 9^n kad rekurzivno stignemo do f(9) (umanjuje se dim za 1 manje pri svakom rek pozivu);
    string ost = n.substr(1); //idemo od pozicije 1
    if(c<3)
        return c*f(devetke)+f(ost);
    else if(c==3)
        return c*f(devetke);
    else
        return (c-1)*f(devetke)+f(ost);
}

int main(){

    string n;
    cin >> n;
    cout << f(n) << endl;

    return 0;
}
