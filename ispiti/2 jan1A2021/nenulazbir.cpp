#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int64_t n;
    cin >> n;
    //koristicemo mape gde je kljuc element niza, a vrednost br pojavljivanja
    unordered_map<int,int>broj_pojavljivanja;
    int64_t brParovaNula=0,x;
    for(int i=0; i<n; i++){
        cin >> x;
        broj_pojavljivanja[x]++; //radimo broj pojavljivanja
        brParovaNula += broj_pojavljivanja[-x]; //pa broj pojavljivanja suprotnih elemenata

        /*
        for (auto const &pair: broj_pojavljivanja) {
            cout << "{" << pair.first << ": " << pair.second << "}\n";
        }
        cout << endl;
        */
    }
    cout << ((n*(n-1))/2) - brParovaNula << endl; //uk broj parova oduzmemo sa onim koji kao zbir formiraju 0
    return 0;
}
/*
 4
3 4 -3 -3
{-3: 0}
{3: 1}

{-4: 0}
{4: 1}
{-3: 0}
{3: 1}

{-4: 0}
{4: 1}
{-3: 1}
{3: 1}

{-4: 0}
{4: 1}
{-3: 2}
{3: 1}
 */
