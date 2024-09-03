#include <iostream>
#include <vector>
using namespace std;

int main(){

    int64_t p,k,n;
    cin >> p >> k >> n;
    vector<int> s(n);
    int64_t num=0;
    for(int i=0; i<n; i++){
        cin >> s[i];
        if(num>=k){ //odsecanje: ne gledamo broj onih koji mogu da omaše k
            break;
        }
        if(s[i]>=p){
            num++;
        }else{
            num=0;
        }
    }
    if(num>=k){
        cout << "da\n";
    }else{
        cout << "ne\n";
    }
    return 0;
}
