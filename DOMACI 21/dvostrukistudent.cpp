#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Studenti{
    string ime,prezime;
};

bool poredi(const Studenti& a, const Studenti& b){
    if(a.ime < b.ime){
        return true;
    }
    else if(a.ime > b.ime){
        return false;
    }
    return a.prezime < b.prezime;
}

int main(){
    ios_base::sync_with_stdio(false);
    string s;
    vector<Studenti> st;
    int64_t brst=0;
    while(getline(cin,s)){
        int p=s.find(' ');
        string ime=s.substr(0,p);
        string prezime=s.substr(p+1);
        st.push_back({ime,prezime});
        brst++;
    }
    sort(begin(st),end(st),poredi);
    for(int i=0; i<brst; i++){
        if(st[i].ime == st[i+1].ime && st[i].prezime == st[i+1].prezime){
            cout << st[i].ime << " " << st[i].prezime << '\n';
            break;
        }
    }
    return 0;
}
