/*
 k=3
 1 4 2 3 2

 put od 0 do k-1:
 ai+2ai+1 + 3ai+2
 = 1+2*4+3*2 = 15

 put od 1 do k

 ai+1 + 2ai+2 + 3ai+3
 ovo se matematicki dokazuje
 <=> ai+ 2ai+1 + 3ai+2 - (ai + ai+1 + ai+2) + k ai+k
 <=> ai+ 2ai+1 + 3ai+2 - ai - ai+1 - ai+2 + k ai+k
 <=> ai+1 + 2ai+2 + 3ai+3 (k ai+k)
 = 4+2*2+3*3 = 17

 Постављањем магнета десно од ове позиције само скраћује пређени пут, па није потребно разматрати га.

 potom sa broja kuglica uklanjamo prvi element i dodajemo onaj koji smo poslednji razmatrali

 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int64_t n,k;
    cin >> n >> k;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int64_t put=0,brKuglica=0,maxput=0;
    for(int i=0; i<k; i++){ //levo od k
        brKuglica += a[i];
        put += (i+1)*a[i];
    }
    //desno od k, pa od drugog elem pa na dalje se razmatra
    for(int i=k; i<n; i++){
        put -= brKuglica;
        put += k*a[i];
        maxput=max(maxput,put);
        brKuglica -= a[i-k];
        brKuglica += a[i];
    }
    cout << maxput << endl;
    return 0;
}
