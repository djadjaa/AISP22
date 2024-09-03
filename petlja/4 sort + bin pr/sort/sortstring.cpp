#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

//izdvajamo fju posebno za poredjenje karaktera kako ne bismo linearno kroz petlju poredili
bool porediKaraktere(char a, char b){
    return tolower(a) < tolower(b);
}

bool poredi(const string &a, const string &b){
    return lexicographical_compare(begin(a),end(a),
                                begin(b),end(b),
                                porediKaraktere); //prima dva niza karaktera i njihov komparator
}

int main(){

    string linija;
    vector<string> l;
    while(cin >> linija){
        l.push_back(linija); //ubacujemo stringove u niz stringova
    }
    sort(begin(l),end(l),poredi);
    for(int i=0; i<l.size(); i++){
        cout << l[i] << '\n';
    }
    return 0;
}
