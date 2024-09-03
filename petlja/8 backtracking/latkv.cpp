#include <iostream>
#include <vector>

using namespace std;

void ispisi(vector<vector<int>> latkv, int n){
   for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
         cout << latkv[i][j];
      }
      cout << endl;
   }
   return;
}

bool pravila(vector<vector<int>> &latkv, int n, int row, int col){
   for(int i=0; i<n; i++){
      if(i!=row && latkv[i][col] == latkv[row][col])
         return true;
   }
   for(int i=0; i<n; i++){
      if(i!=col && latkv[col][i] == latkv[row][col])
         return true;
   }
   return false;
}

bool resi(vector<vector<int>> &latkv, int n, int poz){
   if(poz==n*n-1){//ako smo popunili sva polja
      ispisi(latkv,n);
      return true;
   }
   int r=poz/n,c=poz%n;
   if(latkv[r][c]!=0){//ako je popunjeno polje idemo dalje
      return resi(latkv,n,poz+1);
   }else{
      for(int i=1; i<=n; i++){
         latkv[r][c]=i;
         if(!pravila(latkv,n,r,c)){ //ako ispunjava pravila
            if(resi(latkv,n,poz)){ //ako za dati prefiks postoji resenje
               ispisi(latkv,n);
               return true;
            }
         }
      }
      latkv[r][c]=0;
      return false;
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
   resi(latkv,n,0);
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
