//pravimo niz prefiksnih suma i uslov je pj-pi>=k
//prepolovicemo ponovo niz i trazimo prefiksne sume koje ispunjavaju ovaj uslov; znamo da elementi pre onog koji ne ispunjava uslov zapravo ispunjavaju pa necemo kroz ceo niz proci
//primenicemo i tehniku dva pokazivaca
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> //fja gde mozemo napraviti niz prefiksnih suma
using namespace std;
int brojParova(int l,int d,vector<int>& p,vector<int>& tmp,int k){//tmp je za sort
    if(d-l==1){ //ako imamo samo jedan elem;
        return 0;
    }
    int s=(l+d)/2;
    int brojParovaLevo=brojParova(l,s,p,tmp,k);
    int brojParovaDesno=brojParova(s,d,p,tmp,k);
    int brojParovaMix=0; //tehnika2pok
    int j=l;
    for(int i=s; i<d; i++){
        while(j<s && p[i]-p[j]>=k){
            j++;
        }
        brojParovaMix += j-l;
    }
    merge(begin(p)+l,begin(p)+s,
          begin(p)+s,begin(p)+d,
          begin(tmp)+l);
          //prva polovina,druga polovina i rezultat smestamo u tmp
    copy(begin(tmp)+l,begin(tmp)+d, begin(p)+l);
    return brojParovaLevo+brojParovaDesno+brojParovaMix;
}
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int k;
    cin >> k;
    vector<int> p(n+1); //jer je prva prefiksna suma 0
    partial_sum(begin(a),end(a),begin(p));
    vector<int> tmp(n+1);
    cout << brojParova(0,n+1,p,tmp,k) << '\n';
    return 0;
}
