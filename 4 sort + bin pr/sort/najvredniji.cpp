#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Predmeti{
    string ime;
    float cena;
};

int poredi(const Predmeti a, const Predmeti b){
	if(a.cena > b.cena)
		return 1;
	else
		return 0;
}

int main(){

    float budzet;
    cin >> budzet;
    int64_t n;
    cin >> n;
    vector<Predmeti> p(n);
    for(int i=0; i<n; i++){
        cin >> p[i].ime >> p[i].cena;
    }
    sort(begin(p),end(p),poredi);
    float diff=budzet;
    for(int i=0; i<n && diff > 0 ; i++){
        if(diff-p[i].cena >= 0){
            diff -= p[i].cena;
            cout << p[i].ime << " " << fixed << setprecision(2) << p[i].cena << endl;
        }
    }
    if(diff > 0){
        cout << fixed << setprecision(2) << diff << endl;
    }
    return 0;
}
