#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); //i ovo treba zbog zbira tokom unosa
    int64_t n,sum,sumall;
    cin >> n;
    sum=0;
    sumall=(n*(n+1))/2;
    for(int i=0; i<n; i++){
        int64_t x;
        cin >> x;
        sum += x;
    }
    cout << sumall-sum << '\n';
    return 0;
}
/*
 sumu svih elemenata do n možemo preko gausa odrediti, potom inkrementalno odrediti sumu datih elemenata i onaj koji fali dobijamo oduzimanjem ova dva
 */
