/*
 posmatracemo manje segmente jer ce biti isti rezultati za prvih nekoliko segmenata(za one cija se donja granica zavrsava sa devetkama
 stoga vazice:
 npr [0,2435]=>f(2435)=2*f(999)+f(435) (f(broj brojeva u intervalu)
 [0,435]=[0,99]U[100,199]U[200,299]U[300,399]U[400,435]
          f(99)   f(99)     f(99)       f(0)    f(35) => 3f(99)+f(35)
f(35)=[0,35]=>[0,9]U[10,19]U[20,29]U[30,35]
                f(9) f(9)      f(9)     f(0) => 3f(9)
=> f(cn):(c je prva cifra,n predstavlja ostatak cifara)
ako je c<3 f(cn)=cf(9..9)+f(n) (onoliko devetki koliko n ima cifara)
ako je c=3 f(cn)=3f(9..9)
ako je c>3 f(cn)=(c-1)f(9...9)+f(n)
 */

#include <iostream>
#include <string>
using namespace std;

int f(string n){
    if(n==""){
        return 1;
    }
    int c=n[0]-'0';
    string devetke = string(n.size()-1,'9');
    string ostatak = n.substr(1); //od drugog karaktera pa na vise
    if(c<3){
        return c*f(devetke)+f(ostatak);
    }else if(c==3){
        return c*f(devetke);
    }else{
        return (c-1)*f(devetke)+f(ostatak);
    }
}

int main(){
    string n;
    cin >> n;
    cout << f(n) << '\n';
    return 0;
}

/*
 medjutim imamo ovaj slucaj f(999) = 8*f(99)+f(99) = 9f(99) = 9 * 9 * 9 => 9^n
 i ovaj: f(2435) -> f(435) -> f(35) -> f(5) -> f() i odozdo ka gore racunamo koliko brojeva bez 3 imamo resavanjem veceg problema preko resavanja manjih
 */
