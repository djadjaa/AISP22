#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int prviKojiNijeDeljiv(const vector<long long>&a, long long k){
    //primena binarne pretrage zarad bolje vremenske slozenosti
    int n=a.size();
    int l=0,d=n;
    while(l<=d){
        int s=l+(d-l)/2;
        if(a[s]%k!=0){
            d=s-1;
        }else{
            l=s+1;
        }
    }
    return d+1;
}

/*
 ми на основу инваријанте овог кода знамо да се на позицији l = d налази елемент који
није дељив са k, а да се на позицији l − 1 налази елемент који јесте дељив са k (осим када је l = 0 и тада
нема елемената дељивих са k). Зато крајњи резултат није коректан и потребно га је заменити са d, јер се први
елемент који није дељив са k налази на позицији d.
 */

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //ciscenje bafera
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    long long k;
    while(cin >> k){
        cout << prviKojiNijeDeljiv(a, k) << '\n';
    }
    return 0;
}
