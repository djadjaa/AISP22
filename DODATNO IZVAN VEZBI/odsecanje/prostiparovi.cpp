#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){

    int64_t n;
    cin >> n;
    int64_t num=0;
    //eratostenovo sito
    vector <bool> prost;
    prost.resize(n+1,true);
    prost[0] = prost[1] = false;
    for(int i=2; i<=sqrt(n); i++){
        if(prost[i]){
            for(int j=i*i; j<=n; j+=i){
                prost[j]=false;
            }
        }
    }
    int64_t p=2; //2 je jedini paran prost broj,a svi njegovi umnošci su složeni, pa ih nećemo gledati
    for(int q=p+1; p+q<=n; q++){
        if(prost[q] && prost[p+q]){ //proveravamo da li je drugi par prost a ujedno i zbir oba broja
            num++;
        }
    }
    cout << num << endl;
    return 0;
}
