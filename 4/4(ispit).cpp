//br vrednosti koje se pojavljuju paran br puta
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
    sort(begin(niz),end(niz)); //nlogn
    int duzina=1; //niz od barem jedan elem
    int brojParnih=0;
    for(int i=1; i<n; i++){
        if(niz[i]==niz[i-1]){
            duzina++;
        }else{
            if(duzina%2==0){
                brojParnih++;
            }
            duzina=1;
        }
    }
    //slucaj kada gledamo poslednji segment
    if(duzina%2==0){
        brojParnih++;
    }
    cout << brojParnih << '\n';
    return 0;
}
//nlogn je slozenost zbog sortiranja + dominantniji je od n
