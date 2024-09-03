#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(begin(a),end(a));
    /*
    for(int i=0; i<n; i++){
        cout << a[i] << '\n';
    }
    */
    //proces brisanja duplikata: nalazimo iterator na prvi duplikat, od njega pa do kraja brisemo sve duplikate
    auto it = unique(begin(a),end(a));
    a.erase(it,end(a));
    n=a.size();

    int64_t duzinaseg=1,start=0,maxduzinaseg=1,maxstart=0;
    for(int i=1; i<n; i++){
        if(a[i]-a[i-1]==1){
            duzinaseg++;
        }else{
            duzinaseg=1;
            start=i;
        }
        if(duzinaseg>maxduzinaseg){
            maxduzinaseg=duzinaseg;
            maxstart=start;
        }
    }
    for(int i=maxstart; i<maxstart+maxduzinaseg; i++){
        cout << a[i] << '\n';
    }
    return 0;
}
