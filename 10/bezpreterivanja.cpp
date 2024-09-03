#include <iostream>
#include <vector>

using namespace std;
void generisi(vector<int> &niz,int i,int brUzastopnih, int k){
    if(brUzastopnih>k){
        return;
    }
    if(i==niz.size()){
        for(int x:niz)
            cout << x << ' ';
        cout << '\n';
        return;
    }
    niz[i]=0;//levo
    if(i>0 && niz[i]==niz[i-1]) //zgodnije je gledati prethodnika zato sto bi i bilo -1
        generisi(niz,i+1,brUzastopnih+1,k);
    else
        generisi(niz,i+1,1,k);
    niz[i]=1;//desno
    if(i>0 && niz[i]==niz[i-1])
        generisi(niz,i+1,brUzastopnih+1,k);
    else
        generisi(niz,i+1,1,k);
    //ako stavljmo istu cifru kao malopre bruzasopnih se uvecava a inace se resetuje na 1
}

int main(){

    int n,k;
    cin >> n >> k;
    vector<int> niz(n);
    for(int i=0; i<n; i++){
        cin >> niz[i];
    }
    generisi(niz,0,0,k);

    return 0;
}
