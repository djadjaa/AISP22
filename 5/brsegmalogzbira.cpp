//br segmenta je broj elem u najvecem segmentu
#include <iostream>
#include <algorithm>
#include <vector>

/*
 imamo prazan segment, ubacujemo  prvi elem ako je manji od date vr uvecavamo br segmenata i prosirujemo segment, a ako je veci od date vr smanjujemo segment
 */

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<unsigned> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int t;
    cin >> t;
    int brSegmenata=0;
    int tempzbir=0;
    int j=0;
    for(int i=0; i<n; i++){
        tempzbir += a[i];
        while(tempzbir>=t){
            tempzbir -= a[j++];
        }
        brSegmenata += i-j+1;
    }
    cout << brSegmenata << '\n';
    return 0;
}

//pokazvac i nikad ne moze da se pomera u levo, zato sto su brojevi prirodni
//slozenost je linearna bez obzira na dvostruku petlju, nikad j ne moze preskociti i, u najgorem slucaju j=i+1 pritom vazi j<=n; mi vise od n puta ne mozemo uvecati j; j se nikad ne resetuje
//dakle ako bi se j resetovalo bila bi kvadratna slozenost, ovako je ipak linearna
