#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//trazimo resenja tako da vazi i<j (2 brojaca) i posmatramo zbir a[i]+a[j], ako je zbir > s, j--, ako <s, i++, ako =s, brparova++, i++

int main(){
    int s,n;
    cin >> s >> n;
    vector<int> niz(n);
    for(int i=0; i<n; i++){
        cin >> niz[i];
    }
    sort(begin(niz),end(niz));
    int i=0, j=n-1;
    int brParova=0;
    while(i<j){
        if(niz[i]+niz[j]>s){
            j--;
        }
        else if(niz[i]+niz[j]<s){
            i++;
        }
        else{
            i++;
            j--;
            brParova++;
        }
    }
    cout << brParova << '\n';
    return 0;

//br koraka ne moze uvek biti veci od n-> zato je lin sloz o(n)
}
