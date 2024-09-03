#include <iostream>
using namespace std;
int main(){

    int64_t a,b,k;
    cin >> a >> b >> k;
    int64_t deljividoa = (a-1)/k + 1; //zato što uključujemo 0 u segmentu jer je "deljviva" sa 5, a a-1 zbog zbira elemenata iz dva segmenta
    int64_t deljividob = b/k + 1; //takođe i ovde uključujemo 0 zbog istog razloga;
    if(a>0){ //provera zbog gove navedenog razloga (a-1)
        cout << deljividob-deljividoa << endl;
    }else{
        cout << deljividob << endl;
    }
    return 0;
}
