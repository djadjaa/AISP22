/*
 3 1 2
 4 1 9
 2 2 3
 polazimo iz gornjeg levog krecuci se ili dole ili desno i tako dobiti najveci zbir
 posmatramo puteve koji se zavrsavaju korakom desno ili korakom dole (time se oduzimaju dimenzije m i n)
 maxzbir(n,m)=max(maxzbir(n,m-1),maxzbir(n-1,m)+poslednji elem matrice
 */
#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n;
    cin >> n;
    vector<vector<int>> mat(n,vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> mat[i][j];
        }
    }
    vector<vector<int>> maxZbir(n+1,vector<int>(n+1));
    //ako su m i n 0 maksimalni zbir svih elemenata je 0 jer upravo ti elementi ne postoje
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            maxZbir[i][j]=max(maxZbir[i-1][j],maxZbir[i][j-1])+mat[i-1][j-1];
        }
    }
    cout << maxZbir[n][n] << '\n';
    return 0;
}
/*
 gledamo sl matrice:
 3 1
 4 1
 2 2

 i:
 3 1 2
 4 1 9

 tada je max(z1+poslelem,z2+poslelem) tj max(z1,z2)+poslelem
 */
