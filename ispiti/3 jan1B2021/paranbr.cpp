#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    sort(begin(a),end(a));
    int64_t duzinaNizaTemp = 1; //ima barem 1 elem
    int64_t brojParnih=0; //br parnih pojavljivanja elem
    for(int i=1; i<n; i++){
        if(a[i]==a[i-1])
            duzinaNizaTemp++;
        else{
            if(duzinaNizaTemp%2==0)
                brojParnih++;
            duzinaNizaTemp=1; //ako su razliciti vraćamo se na prvobitnu veličinu
        }
    }
    if(duzinaNizaTemp%2==0)
        brojParnih++;
    cout << brojParnih << endl;
    return 0;
}
