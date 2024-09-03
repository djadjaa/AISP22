//OPTIMIZOVAN KOD
//nece svaki cvor da ima 2 deteta
//o(2^n) jer moramo prolaziti kroz svako podstablo i proveriti da li mozemo te particije da ubacimo u brojac sto je neefikasno, a pritom desavaju se isti rekurzivni pozivi vise puta
//primenicemo memoizaciju gde cemo pamtiti neke vrednosti koje se mogu ponoviti jer rekurzivni pozivi se ponavljaju
//resenje nam se zapravo nalazi u donjem desnom polju matrice memoizacije
#include <iostream>
#include <vector>
using namespace std;
vector <vector<int>> memo;
int brParticija(int n,int maxSabiraka){
    if(memo[n][maxSabiraka]!=-1){ //da li smo do sada upisali vrednost u matricu memoizacije
        return memo[n][maxSabiraka];
    }
    if(n==0){
        return memo[n][maxSabiraka]=1;
    }
    int br=0;
    if(maxSabiraka>1)
        br += brParticija(n,maxSabiraka-1);
    if(maxSabiraka<=n)
        br += brParticija(n-maxSabiraka,maxSabiraka);
    return memo[n][maxSabiraka]=br;
}

int main(){
    int n;
    cin >> n;
    memo = vector<vector<int>> (n+1,vector<int>(n+1,-1)); //-1 jer kada racunamo br particija u najgorem slucaju imacemo samo 1 particiju-dakle bice neprocitano polje
    cout << brParticija(n,n) << '\n';
    return 0;
}
