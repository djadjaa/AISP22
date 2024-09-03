/*
 slozenost = O(n^2) = n*2n
 zvezda ne poznaje nikog ali nju svi poznaju
 prosirenjem matrica proveravacemo samo elemente levo i gore od dijagonale i to samo jedan
 umesto da proveracvamo za svaku osobu koja je zvezda pamticemo onu koja ce biti potencijalna i tako prosirenjem matrice idemo do kraja i zvanicno odredjujemo ko je zvezda proverom njenih vrsta i kolona
 o(n+2n) => o(n)
 poredimo elemente vrste sa elementom kolone
 */
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector <vector<int>> mat(n,vector<int>(n)); //kvadratna matrica
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> mat[i][j];
        }
    }
    //eliminacija nepotencijalnih zvezda
    int zvezda = 0; //potencijalna zvezda
    for(int i=1; i<n; i++){ //prolazimo kroz kolone
        if(mat[zvezda][i]==1){//ako zvezda poznaje i
            zvezda = i; //potencijalna zvezda
        }
    }
    bool zvanicnaZvezda=true;
    for(int i=0; i<n && zvanicnaZvezda; i++){
        //izbegvamo dijagonalu, ako osoba i ne poznaje potencijalnu zvezdu ona nije zvezda
        if(i!=zvezda && !mat[i][zvezda]){
            zvanicnaZvezda=false;
        }
        //analogno, ukoliko potencijalna zvezda poznaje i
        if(i!=zvezda && mat[zvezda][i]){
            zvanicnaZvezda=false;
        }
    }
    //(mat[i][zvezda]==0 ||  mat[i][zvezda]==1) -> ako i zna zvezdu ili ako zvezda zna i
    if(zvanicnaZvezda){
        cout << zvezda << '\n';
    }else{
        cout << "nema\n";
    }
    return 0;
}
/*
 01111
 10101
 00001
 10101
 00000
 */
