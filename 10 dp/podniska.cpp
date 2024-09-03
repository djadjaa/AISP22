#include <bits/stdc++.h>

using namespace std;

/*posmatracemo dva slučaja: kada uklonimo poslednje slovo kako sa jedne tako sa druge niske
 ako je jedan od dva para karatera jednak, uvećamo brojač za jedan i uklonimo karaktere
 u suprotnom uklanjaćemo karaktere kako sa jednog u jednom paru tako sa drugog u drugom paru i tražimo adekvatno rešenje
 ako su niske prazne rešenje je prazan skup

 karaktere ćemo posmatrati u vidu matrice
 */

int main(){

    string s1,s2;
    cin >> s1 >> s2;
    int n1=s1.size(),n2=s2.size();
    vector<vector<int>> dp(n1+1,vector<int>(n2+1)); //+1 zbog terminirajuće nule
    dp[0][0] = 0;
    for(int i=1; i<=n1; i++){
        for(int j=1; j<=n2; j++){
            if(s1[i-1]!=s2[j-1])
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            else
                dp[i][j]= 1+dp[i-1][j-1];
        }
    }
    cout << dp[n1][n2] << endl;

    return 0;
}
