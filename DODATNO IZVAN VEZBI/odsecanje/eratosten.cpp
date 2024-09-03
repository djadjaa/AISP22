#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){

    //kod eratostena odsecanje postoji kod parnih brojeva i kod umnošaka trojke i petice
    int64_t a,b;
    cin >> a >> b;
    int64_t sum=0,num=0;
    vector <bool> prost;
    prost.resize(b+1,true);
    prost[0]=prost[1]=false;
    for(int i=2; i<=sqrt(b); i++){
        if(prost[i]){
            for(int j=i*i; j<=b; j+=i){
                prost[j]=false;
            }
        }
    }
    for(int i=a; i<=b; i++){
        if(prost[i]){
            num++;
            sum+=i;
            sum %= 1000000;
        }
    }
    cout << num << " " << sum << endl;
    return 0;
}
