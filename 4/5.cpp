//brParova datog zbira
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int s,n;
    cin >> s >> n;
    vector<int> niz(n);
    for(int i=0; i<n; i++){
        cin >> niz[i];
    }
    sort(begin(niz),end(niz));
    int brParova=0;
    for(int i=0; i<n; i++){
        int aj=s-niz[i]; //a[i]+a[j]=s
        if(binary_search(begin(niz),begin(niz)+i,aj)){
            brParova++;
        }
    }
    cout << brParova << '\n';
    return 0;
}
//sort nlogn
//+n*binarnapretraga(logn)
