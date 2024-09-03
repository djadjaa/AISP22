#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;
    int f=1; //prazan skup resenja
    int devetke = 1;
    while(n>0){
        int c=n%10;
        if(c<3){
            f=c*devetke+f; //broj resenja se uvecava
        }else if(c==3){
            f=c*devetke;
        }else{
            f=(c-1)*devetke+f;
        }
        devetke *= 9 //ispostavlja se da f(9...9) = 9^brdevetki
        n /= 10;
    }
    cout << f << '\n';

    return 0;
}
