#include <iostream>
using namespace std;
int main(){

    long long n;
    cin >> n;
    int d=2; //invarijanta je da je 2 minimalni broj koji deli broj (1 deli sve brojeve)
    while(n>1){ //sve dok je broj veci od 1 (jer 1 deli samo 1)
        while(n%d==0){ //i sve dok je deljiv sa deliocem
            cout << d << " "; //ispisi ga
            n /= d; //skracuj ga
        }
        d++; //ako nije deljiv idi na sledeci delilac
    }
    cout << '\n';
    return 0;
}
