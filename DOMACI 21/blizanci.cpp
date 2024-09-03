#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main(){

    int64_t m;
    cin >> m;
    vector<int64_t> mo(m);
    for(int i=0; i<m; i++){
        cin >> mo[i];
    }
    sort(begin(mo),end(mo));
    int64_t n;
    cin >> n;
    vector<int64_t> zo(n);
    for(int i=0; i<n; i++){
        cin >> zo[i];
    }
    sort(begin(zo),end(zo));
    int64_t minRazl=INT_MAX, i=0,j=0,razl;
    while(i<m && j<n){
        razl=abs(mo[i]-zo[j]);
        if(razl<minRazl){
            minRazl=razl;
        }
        if(mo[i]<zo[j]){
            i++;
        }else{
            j++;
        }
    }
    cout << minRazl << '\n';
    return 0;
}
