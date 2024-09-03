#include <iostream>
#include <vector>

using namespace std;

bool konflikt(vector<vector<int>> &mat, int i, int j, int n){

    for(int k = 0; k <n; k++)
        if(k != i && mat[i][j] == mat[k][j])
            return true;

    for(int k = 0; k<n; k++)
        if(k != j && mat[i][j] == mat[i][k])
            return true;

    return false;

}

bool sudoku(vector<vector<int>> &mat, int rbr, int n){

    int i = rbr/n, j = rbr%n;

    if(mat[i][j] != 0){
        if(rbr == n*n-1)
            return true;

        return sudoku(mat, rbr+1, n);
    }else{

        for(int k = 1; k<=n; k++){

            mat[i][j] = k;
            if(!konflikt(mat, i, j, n))
                if(sudoku(mat, rbr, n))
                    return true;
        }
        mat[i][j] = 0;
        return false;

    }
}

void obradi(vector<vector<int>> matrica){

    int n = matrica.size();

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++)
            cout << matrica[i][j] << " ";
        cout << '\n';
    }

    return;
}

int main(){

    int n;
    cin >> n;

    vector<vector<int>> matrica;
    matrica = vector<vector<int>>(n, vector<int>(n, 0));

    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            cin >> matrica[i][j];


    if(sudoku(matrica, 0, n))
        obradi(matrica);


    return 0;
}
