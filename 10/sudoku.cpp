//resenje bice list (samo jedno resenje) i necemo time ici kroz celo stablo pretrage
#include <iostream>
#include <vector>
//bektreking - kad se vratimo tako da nadjemo adekvantno resenje
using namespace std;
//poenta je da u svakom  koraku na odredjeno mesto(ako je prazno) da upisemo brojeve koje smemo pritom proveravamo da li smemo da upisemo i potom pozivamo rekurzivni poziv za prelazak na naredno polje
//provera uslova:
bool provera(vector<string> &sudoku, int r, int c){ //konvencije u samoj igri
    for(int k=0; k<9; k++){
        if(k!=r && sudoku[k][c] == sudoku[r][c]){
            return false;
        }
    }
    for(int k=0; k<9; k++){
        if(k!=c && sudoku[r][k] == sudoku[r][c]){
            return false;
        }
    }
    //gledamo pojedinacne kvadratice
    int ogrCol=(c/3)*3, ogrRow=(r/3)*3;
    for(int k=ogrRow; k<ogrRow+3; k++){
        for(int l=ogrCol; l<ogrCol+3; l++){
            if(!(k==r && l==c) && sudoku[k][l]==sudoku[r][c]){
                return false;
            }
        }
    }
    return true;
}

//fja vraca t ili f u zavisnosti od toga da li smo pronasli resenje sa uveliko fiksiranim + sa onim poljima koje smo mi fiksirali sami -> tako gradimo resenje
bool rrrrrrresi(vector<string> &sudoku, int i){ //i je trenutna poz
    if(i==81){
        return true; //sva su polja popunjena i pritom nismo prekinuli pretragu
    }
    //vrste dobijamo kao i/brredova a kolone i%brredova
    //r-row c-column
    int r=i/9;
    int c=i%9;
    if(sudoku[r][c]!='0'){ //ako nije upisano 0, polje je popunjeno
        return rrrrrrresi(sudoku,i+1); //ako je popunjeno idi dalje, to polje je u startu popunjeno
    }
    //a ako nije popunjeno polje
    for(char vr='1'; vr<='9'; vr++){
        sudoku[r][c]=vr;//postavljamo vr na to polje
        //ako vazi za to polje ovo:
        if(provera(sudoku,r,c)) //ako su konvencije ispunjene izvrsavmo rek poziv
            if(rrrrrrresi(sudoku,i+1)) //ako postoji resenje (za prefiks)
                return true; //tada za celo podstablo vazi da ima resenje; ova linija predstavlja odsecanje tj nemaa potrebe da trazimo kroz matrice za koje znamo da nema resenja
    }
    //inace ako nema resenja idemo dalje kroz pretragu, tj idemo ponovo na petlju
    sudoku[r][c]='0';  //vracamo vr na 0
    return false; //a inace vazi da nema resenja uopste za to podstablo
    //nijedan od ovih 9 brojeva ne vraca true pa ce vratiti false
}

int main(){
    vector<string> sudoku(9);
    for(int i=0; i<9; i++){
        cin >> sudoku[i];
    }
    if(rrrrrrresi(sudoku,0)){
        for(string r:sudoku)
            cout << r << '\n';
    }else{
        cout << "nema\n";
    }
    return 0;
}
