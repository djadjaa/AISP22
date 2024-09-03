#include <iostream>
#include <cmath>
using namespace std;

bool prost(int64_t n){
    if(n==1){
        return false;
    }
    if(n==2){
        return true;
    }
    //ako je br paran, on automatski nije prost, stoga gledaćemo neparne brojeve
    for(int i=3; i<sqrt(n); i+=2){ //proverićemo do njegovog korena, ako je rezultat korena ceo broj, on nije prost
        /*
         Jedna od karakteristika brojeva je da, ako imaju par faktora, jedan od faktora mora biti jednak ili manji od kvadratnog korena. Dakle, ako testirate sve brojeve do kvadratnog korena, možete biti sigurni da je broj prost.
         */
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int main(){

    int64_t n;
    cin >> n;
    if(prost(n)){
        cout << "DA\n";
    }else{
        cout << "NE\n";
    }

    return 0;
}
