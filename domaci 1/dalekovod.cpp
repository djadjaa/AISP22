/*
 najoptimalnije je da posmatramo srednju kuću
 ako izaberemo poziciju kuće koja nije od krajnjih, pomeranje za jedan na desno skraćuje sumu dužine
 kablova za 1 za svaku kuću koja je sa desne strane a povećava sumu dužina kablova za 1 za svaku kuću
 koja je sa leve strane
 stoga, ako imamo više kuća sa desne nego sa leve, pomeranje za jedan na desno će uvek skratiti
 sumu dužinu kablova
 i obrnuto
 ako imamo paran broj kuća, nevažno je koju od dve središnje biramo
 ako imamo neparan broj kuća, uzimamo baš središnju

 tražimo udaljenost na koju ćemo postaviti dalekovod takvu da zbir udaljenosti od njega bude minimalan
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){

    int64_t n;
    cin >> n;
    vector<int64_t> kuce(n);
    for(int i=0; i<n; i++)
        cin >> kuce[i];
    sort(begin(kuce),end(kuce));
    int64_t kabl=0;
    for(int i=0; i<n; i++)
        kabl += abs(kuce[n/2]-kuce[i]);

    cout << kabl << endl;
    return 0;
}
