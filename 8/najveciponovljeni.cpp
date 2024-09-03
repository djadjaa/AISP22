//proveravamo levo od trenutnog elem da li se ponavlja i azuriramo maksimum (o(nlogn))

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int main(){
    int n,x;
    cin >> n;
    set<int> duplikati;
    int maks=0;
    while(n--){
        cin >> x;
        if(duplikati.find(x)!=end(duplikati)){
            maks=max(maks,x);
        }
        duplikati.insert(x);
    }
    if(maks==0){
        cout << "nema\n";
    }else{
        cout << maks << '\n';
    }
    return 0;
}
