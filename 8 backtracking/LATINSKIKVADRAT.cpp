#include <iostream>
#include <vector>

using namespace std;

bool pravila(vector<vector<int>> &latkv, int n, int row, int col, int val){
   for(int i=0; i<n; i++){
       if(latkv[i][col] == val || latkv[row][i] == val)
           return false;
   }
   return true;
}

void resi(vector<vector<int>>&latkv, int n, int row, int col){
    if(row==n-1 && col==n){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << latkv[i][j];
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    if(col==n){
        row++;
        col=0;
    }
    if(latkv[row][col]!=0){
        resi(latkv,n,row,col+1);
        return;
    }
    //int r=poz/n,c=poz%n;
    for(int i=1; i<=n; i++){
        if(pravila(latkv,n,row,col,i)){
            latkv[row][col]=i;
            resi(latkv,n,row,col+1);
            latkv[row][col]=0;
        }
    }
}

int main(){

    int n;
    cin >> n;
    vector<vector<int>> latkv(n,vector<int>(n,0));
    for(int i=0; i<n; i++){
       for(int j=0; j<n; j++){
          cin >> latkv[i][j];
      }
   }
   resi(latkv,n,0,0);
   return 0;
}

/*
 void pretraga(const vector<int>& v, int k) {
   if (odsecanje(v, k))
      return;
   if (jesteResenje(v, k))
      ispisi(v, k);
   for (int x : kandidati(v, k)) {
      v[k] = x;
      pretraga(v, k+1);
   }
}
 */
