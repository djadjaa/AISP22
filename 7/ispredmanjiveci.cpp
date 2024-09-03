//ovde koristimo deque -> red koji ima dva kraja
//zbog svojstva niza (tekst zadatka) dovoljno je proveriti samo za jedan broj da li je manji ili veci od njega jer svi elementi ispred njega su ili veci ili manji
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int main(){

    int64_t n;
    cin >> n;
    int64_t temp;
    deque<int64_t> d;
    cin >> temp;
    d.push_front(temp);
    for(int i=1; i<n; i++){
        cin >> temp;
        if(temp < d.front()){
            d.push_front(temp);
        }else{
            d.push_back(temp);
        }
    }

    for(int i=0; i<n; i++){
        cout << d[i] << " ";
    }
    cout << '\n';
    return 0;
}
//mozemo i u petlji da unesemo brojeve i da proverimo da li je dek prazan preko d.empty()
