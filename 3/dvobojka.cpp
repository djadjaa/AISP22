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
    //linearno vreme -> o(n)
    //idu prvo parni pa neparni
    int k=0; //na pocetku su svi nepoznati
    for(int i=0; i<n; i++){
        if(niz[i]%2==0){
            swap(niz[i],niz[k++]); // ako je element paran razmenjujemo ga sa prvim neparnim, a inace idemo dalje
        }
    }
    for(int i=0; i<n; i++){
        cout << niz[i] << " ";
    }
    cout << '\n';
    return 0;
}
