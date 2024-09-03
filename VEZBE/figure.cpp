#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int64_t minRazlika(int64_t brFigurica, int64_t k, vector<int64_t>jacine){
    int64_t rezultat=INT_MAX;
    for(int i=0; i+k-1<brFigurica; i++){
        rezultat=min(rezultat,k*(jacine[i+k-1]-jacine[i]));
    }
    return rezultat;
}

int main(){

    int64_t brFigurica;
    cin >> brFigurica;
    vector<int64_t> jacine(brFigurica);
    for(int i=0; i<brFigurica; i++){
        cin >> jacine[i];
    }
    sort(begin(jacine),end(jacine));
    int64_t granica;
    cin >> granica;
    int64_t l=0,d=brFigurica-1,rez,razl;
    while(l<=d){
        int64_t s=(l+d)/2;
        int64_t minrazl = minRazlika(brFigurica,s,jacine);
        if(minrazl<=granica){
            l=s+1;
            rez=s;
            razl=minrazl;
        }else{
            d=s-1;
        }
    }
    cout << rez << " " << razl << '\n';
    return 0;
}
