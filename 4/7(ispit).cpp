//svaki elem zamenimo njegovim rangom (broj elem niza koji su strogo manji od njega)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> niz(n);
    for(int i=0; i<n; i++){
        cin >> niz[i];
    }
    vector<int> sortiran = niz;
    sort(begin(sortiran),end(sortiran));
    for(auto x: niz){
        auto it = lower_bound(begin(sortiran),end(sortiran),x);
        cout << it-begin(sortiran) << ' ' ;
    }
    return 0;
}
//za svaki elem koristimon binarnu pretragu i odredjujemo njegov rang
