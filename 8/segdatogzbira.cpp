//koristicemo prefiksne sume; pi- zbir prefiksa duzine i;
//prefiksnu sumu i br pojavljivanja cuvamo u mapi
#include <iostream>
#include <map>
using namespace std;
int main(){

    int z,n,x; // z je trazeni zbir
    cin >> z >> n;
    map<int,int> brPrefiksa;//kljuc je prefiksna suma, a vr koliko se ta prefiksna suma pojavila
    //na pocetku ta mapa nije prazna
    brPrefiksa[0]=1; //prefiksna suma je 0 i njeno pojavljivanje je jedno
    int brSeg=0;
    int tempSuma=0;
    while(n--){
        cin >> x;
        tempSuma += x; //dodajemo na prefiksnu sumu trenutni elem
        brSeg += brPrefiksa[tempSuma-z]; //pi=pj+1-z
        brPrefiksa[tempSuma]++; //inkrementiramo br pojavljivanja trenutne prefiksne sume
    }
    cout << brSeg << '\n';
    return 0;
}
