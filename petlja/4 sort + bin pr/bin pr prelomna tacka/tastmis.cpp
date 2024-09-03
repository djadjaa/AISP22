#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(){

    int64_t t,m;
    cin >> t;
    vector<int64_t> tast(t);
    for(int i=0; i<t; i++)
        cin >> tast[i];

    sort(begin(tast),end(tast));

    cin >> m;
    vector<int64_t> mis(m);
    for(int i=0; i<m; i++)
        cin >> mis[i];

    sort(begin(mis), end(mis));

    int64_t budzet;
    cin >>budzet;

    int64_t rez=INT_MIN;

    for(int64_t t:tast){
        auto it = upper_bound(begin(mis),end(mis),budzet-t);
        if(it==begin(mis)){ //gledamo u desno kada trazimo upper_bound
            break;
        }
        int64_t cena = t+*prev(it); //prev jer upper_bound pokazuje na prvi veci element od datog
        //cout << cena << '\n';
        rez = max(rez,cena);
    }
    cout << rez << endl;
    return 0;
}
