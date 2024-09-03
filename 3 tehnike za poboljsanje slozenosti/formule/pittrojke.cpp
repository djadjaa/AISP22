#include <iostream>
#include <cmath>
using namespace std;

int main(){

    int64_t n;
    cin >> n;

    for(int a=1; 2*a*a<=n*n; a++){
        for(int b=a; b*b<=n*n-a*a; b++){
            double c=sqrt(a*a+b*b);
            int rez=round(c); //ovom fjom proveravamo da li je vr celobrojna
            if(c==rez){
                cout << a << " " << b << " " << c << " " << endl;
            }
        }
    }

    return 0;
}
/*
 znamo da su a.b,c i n u relaciji <= redom. time su i njihovi kvadrati u istoj relaciji. kako je c²=a²+b² a c²<=n² i a²<=b² možemo b u zbiru da zamenimo sa a i dobijamo da je 2a²<=n² i b²<=n²-a² (jer je a²+b²<=n²)
međutim zbog kubne složenosti, možemo samo da proverimo uslov da li važi da je c=sqrt(a²+b²) celobrojna vrednost i time dobijamo kvadratnu složenost
a ide od 1, a b ide od a (jer je a<=b tj a može biti jednak b)
 */
