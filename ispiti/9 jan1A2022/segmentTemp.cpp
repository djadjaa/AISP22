#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){

    int n,z;
    cin >> n >> z;
    vector<int64_t> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int64_t prefixSum=0;
    int64_t a,b,poz1=0,poz2=n-1; //ove dve pozicije predstavljaju ceo interval [0,n-1]
    unordered_map<int64_t,int64_t> ps; //kljuc je suma prefiksa, a vrednost je indeks na kom se ta suma nalazi
    ps[0]=0;
    for(int i=0; i<n; i++){
        prefixSum += arr[i];
        if(ps.find(prefixSum-z)!=ps.end()){ //ako se suma nalazi u mapi
            a = ps[prefixSum-z]; //vrednost kljuca je indeks trazene sume
            b = i;
            if(b-a<poz2-poz1){
                poz1 = a;
                poz2 = b;
            }
        }
        ps[prefixSum]=i+1; //a inače je ubacujemo
    }
    cout << poz1 << ' ' << poz2 << endl;
    return 0;
}
