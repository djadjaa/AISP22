#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){

    string s;
    cin >> s;
    int sLen=s.size();
    vector<uint64_t> dp(sLen+1);
    //prefiks duzine nula je prazan string/skup
    dp[0]=dp[1]=1;
    for(int i=2; i<=sLen; i++){
        int b1=s[i-1]-'0'; //ako uzimamo 1 cifru
        int b2=(s[i-2]-'0')*10 + (s[i-1]-'0'); //a potom drugu cifru
        //uint64_t br=0; nije nam neophodno jer direktno u niz smestamo rezultat
        if(br!=0){ //jedini nacin da nece dekodiranje uspeti je da imamo 0 kao ascii kod
            dp[i] += dp[i-1];
        }
        if(b2>=10 && b2<=26){ //ako ne pocinje nulom i ako sadrzi cifru kojom mozemo kodirati
            dp[i] += dp[i-2];
        }
    }
    cout << dp[sLen] << '\n';
    return 0;
}
