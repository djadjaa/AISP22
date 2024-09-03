#include <iostream>

using namespace std;

int main(){
    long long m,n;
    cin >> m >> n;
    long long al=0,bl=1,ad=1,bd=0;
    while(true){
        long long a=al+ad,b=bl+bd;
        if(m*b < n*a){ //ako je m/n < l/d (al+bl/ad+bd)
            cout << 'L';
            ad=a;
            bd=b;
        }else if(m*b > n*a){ //u suprotnom
            cout << 'D';
            al=a;
            bl=b;
        }else{ //ako smo stigli do tog razlomka
            break;
        }
    }
    cout << '\n';
    return 0;
}
