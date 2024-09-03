#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 -68 -11 -4 13 15 29
 krecemo od -68 uvecavamo jedan pokazivac i racunamo broj kuca sve dok ne dodjemo do rastojanja koje ne ispunjava uslov za 2d (2d jer je svetiljka levo i desno od kuce) i tada uvecavamo drugi pokazivac sve dok se ponovo ne ispostavi da rastojanje ispunjava uslov za 2d
 */

int main(){

    int64_t n;
    cin>>n;
    vector<int64_t>a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(begin(a),end(a));
    int64_t d;
    cin >> d;
    int64_t j=0,maxBrKuca=0;
    for(int i=0; i<n; i++){
        while(a[i]-a[j]>2*d){ //sve dok se ne ispunjava uslov uvecaj drugi pokazivac koji ce da ide na poslednju kucu koja ce biti osvetljena
            j++;
        }
        maxBrKuca=max(maxBrKuca,i-j+1);
    }
    cout << maxBrKuca << '\n';
    return 0;
}
