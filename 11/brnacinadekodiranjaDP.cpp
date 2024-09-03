#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<uint64_t> memo;
uint64_t brDekodiranja(string &s, int n){
    if(memo[n]!=-1){
        return memo[n];
    }
    if(n<=1){//tada imamo samo 1 karakter
        return memo[n]=1;
    }
    int b1=s[n-1]-'0'; //ako uzimamo 1 cifru
    int b2=(s[n-2]-'0')*10 + (s[n-1]-'0'); //a potom drugu cifru
    uint64_t br=0;
    if(br!=0){ //jedini nacin da nece dekodiranje uspeti je da imamo 0 kao ascii kod
        br += brDekodiranja(s,n-1);
    }
    if(b2>=10 && b2<=26){ //ako ne pocinje nulom i ako sadrzi cifru kojom mozemo kodirati
        br+=brDekodiranja(s,n-2);
    }
    return memo[n]=br;
}

int main(){

    string s;
    cin >> s;
    memo=vector<uint64_t>(s.size()+1,-1); //jer gledamo potom i celokupan string
    cout << brDekodiranja(s,s.size()) << '\n';
    return 0;
}
