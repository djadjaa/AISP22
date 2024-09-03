/*
 primena mapa

0: miroslav - 1 glas < k -> plasirani=0;
0: dragan - 1 glas < k -> plasirani=0;
0: miroslav - 2 klasa < k -> plasirani=0;
0: marko - 1 glas < k -> plasirani=0;
1: miroslav - 3 glasa = k -> plasirani=1;
1: dragan - 2 glasa < k -> dragan nije plasiran pa je br plasiranih i dalje 1
2: dragan - 3 glasa = k -> dragan se plasira pa se br plasiranih uvecava za 1
2: miroslav - 4 glasa > k -> miroslav se uveliko plasirao pa br plasiranih ostaje isti i zato stavljamo uslov da je br glasova = k a ne >k da bismo sprecili duplirane plasirane
 */

#include <iostream>
#include <map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int64_t k,n;
    cin >> k >> n;
    map<string,int> brGl;
    int plasirani=0;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        brGl[s]++;
        if(brGl[s] == k){
            plasirani++;
        }
        cout << plasirani << '\n';
    }
    return 0;
}
