#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int64_t n;
    cin >> n;
    vector<int64_t> drva(n);
    for(int i=0; i<n; i++){
        cin >> drva[i];
    }
    int64_t visinaTestere;
    cin >> visinaTestere;
    int64_t l=0, d=*max_element(begin(drva),end(drva));
    while(l<=d){
        int64_t s=l+(d-l)/2;
        int64_t komada=0;
        for(auto x : drva){
            if(x>=s){
                komada += x-s;
            }
        }
        if(komada>=visinaTestere){
            l=s+1;
        }else{
            d=s-1;
        }
    }
    cout << d << '\n';
    return 0;
}
