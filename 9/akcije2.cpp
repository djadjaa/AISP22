//tehnika dva pokazivaca
//t(n)=2t(n/2)+o(nlogn)->o(nlog^2n)
//zbog poboljsane slozenosti, ojacacemo induktivnu hipotezu
//idemo kroz niz b i poredimo sa elementima niza a

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int brParova(int l,int d, vector<int>&a, vector<int>&temp){ //zbog merge sorta uvodimo pomocni niz
    //ako imamo tacno jedan elem u segmentu
    if(d-l==1){
        return 0; //tada segment nema nikakve parove
    }
    int s=(l+d)/2;
    int brojParovaLevo=brojParova(l,s,a);
    int brojParovaDesno=brojParova(s,d,a);
    int brojParovaMix=0; //tehnika 2 pokazivaca
    int j=l;
    for(int i=s; i<d; i++){
        while(j<s && a[j] < a[i]){
            j++;
        }
        brojParovaMix+=j-l;
        //[l,s],[s,d) - i se krece kroz desni  a j kroz levi deo
    }
    //merge sort
    merge(begin(a)+l,begin(a)+s,
          begin(a)+s,begin(a)+d,
          begin(tmp)+l);
    copy(begin(tmp)+l,begin(tmp)+d),begin(a)+l);
    return brojParovaLevo+brojParovaDesno+brojParovaMix;
}

int main(){

    int n;
    cin >> n;
    vector<int> akcije(n);
    for(int i=0; i<n; i++){
        cin >> akcije[i];
    }
    vector<int> temp(n);
    cout << brojParova(0,n,akcije,temp) << '\n';
    return 0;
}
