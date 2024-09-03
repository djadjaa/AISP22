#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
//vektor pomeraja parova
vector<pair<int,int>> potezi = {
    {-1,-2},{-1,2},{1,-2},{1,2},
    {-2,-1},{-2,1},{2,-1},{2,1}
    };
//skakac ide na svako trece polje->zato su ove vrednosti, negativne i pozitivne vrednosti predstavljaju strane
int n,m;
void generisi(vector<vector<int>>&tabla,int i,int j,int br){ //prosledjujemo sahovsku tablu i trenutno polje na koje se nalazi skakac, br je brojac popunjennih polja vrednosti
    tabla[i][j]=br;
    if(br==n*m){
        for(auto& r : tabla){ //referenca jer izvlacimo ceo red iz table
            for(int vr : r){
                cout << setw(2) << vr << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
    for(auto p:potezi){
        //gledamo da li je potez ispravan i ako jeste vrsimo rek poz
        int ni=i+p.first, nj = j+p.second; //nove koordinate
        if(ni>=0 && ni<n && nj>=0 && nj<m && tabla[ni][nj]==0){
            generisi(tabla,ni,nj,br+1); //kada vrsimo rekurzivan poziv uvecavamo br za 1
        }
    }
    //postavicemo nulu jer nismo isli na to polje
    tabla[i][j]=0;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> tabla(n,vector<int>(m));
    generisi(tabla,0,0,1); //1 jer krecemo od polja na kom se nalazi konj
    cout << '\n';
    return 0;
}
