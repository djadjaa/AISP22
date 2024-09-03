#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool ispitajRastojanje(int rastD, int brKuca, vector<int64_t>lokacije, int brLok){
    int64_t poslednjaKuca=lokacije[0];
    brKuca--;
    for(int i=1; i<brLok && brKuca>0; i++){
        if(lokacije[i]-poslednjaKuca>=rastD){
            poslednjaKuca=lokacije[i];
            brKuca--;
        }
    }
    return brKuca==0;
}

int main(){

    int64_t brKuca, brLok;
    cin >> brKuca >> brLok;
    vector<int64_t> lokacije(brLok);
    for(int i=0; i<brLok; i++){
        cin >> lokacije[i];
    }
    sort(begin(lokacije),end(lokacije));
    /* OVO DAJE LOSU SLOZENOST
    int64_t rastD=1;
    while(ispitajRastojanje(rastD,brKuca,lokacije,brLok)){
        rastD++;
    }
    cout << rastD-1 << '\n';
    */
    int64_t l=1, d=lokacije[brLok-1],rez;
    while(l<=d){
        int64_t s=(l+d)/2;
        if(ispitajRastojanje(s,brKuca,lokacije,brLok)){
            l=s+1;
            rez=s;
            //[s+1,d]
        }else{
            d=s-1;
            //[l,s-1]
        }
    }
    cout << rez << '\n';
    return 0;
}
