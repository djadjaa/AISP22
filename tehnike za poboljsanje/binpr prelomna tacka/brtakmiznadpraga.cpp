#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //upper bound veci od trenutnog elementa upper_bound(5)=6
    //lower bound manji od najveceg lower_bound(5)=4 (pod uslovom da 4 i 6 pripadaju skupu)

    int64_t n,m;
    cin >> n;
    vector<int64_t> t(n);
    for(int i=0; i<n; i++){
        cin >> t[i];
    }
    cin >> m;
    int64_t prag;
    while(m--){
        cin >> prag;
        auto it=upper_bound(begin(t),end(t),prag,greater<int>()); //greater stavljamo jer radimo sa opadajucim nizom
        /*
        if(it==end(t)){
            cout << '0' << '\n';
        }
        */
        cout << it - begin(t) << '\n';
    }
    /*
     for(int j=0; j<n; j++){
            if(t[j]>=prag){
                br++;
            }
        }
     */
    return 0;
}
