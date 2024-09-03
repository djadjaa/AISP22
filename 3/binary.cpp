#include <iostream>
#include <vector>
using namespace std;

int main(){

    unsigned long long n;
    cin >> n;
    bool binary[32]={false}; //tzv maska: 0000000
    for(int i=0; n>0; i++, n/=2){
        binary[i]=n%2; //u niz smesti ostatke
    }
    for(int i=31; i>=0; i--){
        cout << (binary[i] ? '1' : '0'); //stampaj da li je ostatak 1 ili 0
    }
    cout << '\n';
    return 0;
}
