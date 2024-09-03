#include <iostream>
using namespace std;
int main(){

    int64_t n;
    cin >> n;
    int64_t prethodni,tekuci,num=0,tempnum=0;
    cin >> prethodni;
    for(int i=1; i<n; i++){
        cin >> tekuci;
        if(tekuci > prethodni){
            tempnum++; //broj onih gde je a>=b
            num += tempnum; //uk broj segmenta gde prvi uslov važi
        }else{
            tempnum=0; //ako ne važi uslov vrši se odsecanje
        }
        prethodni = tekuci;
    }
    cout << num << endl;
    return 0;
}
