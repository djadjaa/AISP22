#include <iostream>
#include <vector>
//generisanje permutacije
using namespace std;

void sviStepenasti(vector<int>& niz, int i){
    if(i==niz.size()){ //ako smo stigli do kraja
        for(int x:niz){
            cout << x << ' ';
        }
        cout << '\n';
        return;
    }
    niz[i]=niz[i-1];
    nizStepenasti(niz,i+1);
    niz[i]=niz[i-1]+1;
    nizStepenasti(niz,i+1);
}

int main(){
    int n;
    cin >> n;
    vector<int> niz(n);
    niz[0]=1;
    sviStepenasti(niz,1);
    return 0;
}
