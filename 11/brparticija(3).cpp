//ideja je da direktno u matrici cuvamo rezultate
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>>dp = vector<vector<int>> (n+1,vector<int>(n+1,0)); //jer racunamo redom polja matrice, ne proveravamo vise da li se desilo izracunavanje
    //za vrednost 0 znamo da su sabirci iskljucivo jedinice
    dp[0]=vector<int>(n+1,1); //postavljamo prvu vrstu na sve jedinice
    for(int i=1; i<=n; i++){
        for(int maxSabiraka=1;maxSabiraka<=n;maxSabiraka++){
            int br=0;
            //da je maxSabiraka=0 nista od ovih uslova se ne bi ispunilo, stoga inicijalizujemo promenljivu na 1
            if(maxSabiraka>1)
                br += dp[i][maxSabiraka-1];
            if(maxSabiraka<=n){
                br +=dp[i-maxSabiraka][maxSabiraka];
            }
            dp[i][maxSabiraka]=br;
        }
    }
    cout << dp[n][n] << '\n';
    return 0;
}
/*
 dp[i][j]=brParticija(i,j)
 */
