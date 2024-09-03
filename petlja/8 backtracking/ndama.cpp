/*
 2 dame ne smeju biti u istoj koloni, dijagonali i vrsti
 */
#include <iostream>
#include <vector>

using namespace std;

void ispisi(vector<int>& kolone, int n){
    for(int i=0; i<n; i++)
        cout << kolone[i]+1 << ' ';
    cout << endl;
}

bool queenAttack(int tempRow, vector<int>& kolone){
    for(int ri=0; ri<tempRow; ri++){ //gledamo prethodno postavljene dame
        if(kolone[ri]==kolone[tempRow]) //ako je prethodno postavljena dama u istoj koloni sa tekućom
            return true;
        if(abs(tempRow-ri) == abs(kolone[tempRow]-kolone[ri])) //ista dijagonala; u pitanju su njihova rastojanja
            //razlog zasto radimo kolone[tempRow]-kolone[ri] je zato sto u niz smestamo pozicije
            return true;
    }
    return false;
}

void nQueens(int tempRow, int n, vector<int>& kolone){
    if(tempRow==n)
        ispisi(kolone,n);
    else{
        for(int i=0; i<n; i++){ //kolone
            kolone[tempRow] = i;
            cout << tempRow << ',' << i << ':' << kolone[tempRow] << endl;
            if(!(queenAttack(tempRow,kolone))){ //radimo negaciju da bismo mogli da se pomeramo, napadaju se pa moramo da pomeramo figuru
                cout << "ne napadaju se " << tempRow << ',' << i << ':' << kolone[tempRow] << endl;
                nQueens(tempRow+1,n,kolone);
            }
        }
    }
}

void nDama(int n){
    vector<int> kolone(n);
    nQueens(0,n,kolone); //krecemo od 0. vrste tj ona nam predstavlja ujedno i br popunjenih elem
}

int main(){
    int n;
    cin >> n;
    nDama(n);
    return 0;
}

/*
 * 4
0,0:0
ne napadaju se
0,1:0
1,1:1
2,1:2
ne napadaju se
0,2:0
1,2:1
2,2:2
3,2:3
3,1:3
ne napadaju se
0,2:0
1,2:1
ne napadaju se
0,3:0
1,3:1
2,3:2
3,3:3
2,2:2
3,2:3
1,0:1
ne napadaju se
0,1:0
1,1:1
2,1:2
3,1:3
ne napadaju se
0,2:0
ne napadaju se
0,3:0
1,3:1
2,3:2
ne napadaju se
2 4 1 3
---------------
3,3:3
1,2:1
2,2:2
3,2:3
2,0:2
ne napadaju se
0,1:0
ne napadaju se
0,2:0
1,2:1
2,2:2
3,2:3
ne napadaju se
0,3:0
1,3:1
ne napadaju se
3 1 4 2
---------------
2,3:2
3,3:3
1,1:1
2,1:2
3,1:3
3,0:3
ne napadaju se
0,1:0
ne napadaju se
0,2:0
1,2:1
2,2:2
ne napadaju se
0,3:0
1,3:1
2,3:2
3,3:3
3,2:3
1,1:1
ne napadaju se
0,2:0
1,2:1
2,2:2
3,2:3
2,1:2
3,1:3
 */
