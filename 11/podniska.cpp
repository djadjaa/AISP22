/*
 ababcb
 babbca
 ->babc im je zajednicka podniska koja je pritom i najduza
 krecemo od poslednjeg karaktera niski gde jedan od ta dva karaktera nije sigurno u najduzem zajednickom podstringu
 posto nemamo info o najduzem podstringu:
 1. deo skupa - gledamo one koje se ne zavrsavaju sa (npr) c:
 abacb i babbca
 2. -||- - ne zavrsavaju sa (npr) a:
 abacbc i babbc
 iz ta dva skupa mozemo odrediti najveci podstring potom maksimum od njih
 zbog poklapanja stringova nije korektno da samo saberemo 1. i 2. deo skupa jer desice se da se u jednom skupu koji ispunjava uslov nalazi onaj koji NE ispunjava drugi uslov skupa i sabiranjem dolazi se do preklapanja
 -------
 ako su im karakteri jednaki:
 kada im uklonimo tada mozemo proceniti najduzi podstring manjih dimenzija i dodati taj isti karakter
 */
#include <iostream>
#include <vector>
#include <string>
int main(){
    string a,b;
    cin >> a >> b;
    int n=a.size(),m=b.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    for(int i=1; i<=n; i++){ //polazimo od 1 jer ako je jedan od stringova prazan string resenje najduzeg podstringa bice bas 0
        for(int j=1; j<=m; j++){
            if(a[i-1]!=b[j-1]){
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }else{
                dp[i][j]=1+dp[i-1][j-1];
            }
        }
    }
    cout << dp[n][m] << '\n';
    return 0;
}
