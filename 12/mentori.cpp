/*
 10 20 40 50
 20 je mentor 10
 40 je mentor 20
 medjutim 50 ne moze da bude mentor 40 zbog malog rejtinga
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    return 0;
}
