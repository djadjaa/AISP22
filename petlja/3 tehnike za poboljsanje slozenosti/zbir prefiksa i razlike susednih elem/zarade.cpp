#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int64_t n;
    cin >> n;
    vector<int64_t> array(n);
    for(int i=0; i<n; i++){
        cin >> array[i];
    }
    vector<int64_t> prefix(n+1); //svi su na nuli
    //da ne bismo stalno računali ispočetka prefiksnu sumu, na tekuću prefiksnu dodamo novi element i time primenimo inkrementalnost
    /*
    for(int i=0; i<n; i++){
        prefix[i+1]=prefix[i]+array[i];
    }
    */

    partial_sum(begin(array),end(array),begin(prefix)+1); //+1 jer ostavljamo na početku 0

    int m;
    cin >> m;

    /*LOSA SLOZENOST
    while(m--){
        cin >> a >> b;
        int64_t sum1=0,sum2=0;
        for(int i=0; i<=b; i++)
            sum1 += array[i];
        for(int i=0; i<=a-1; i++)
            sum2 += array[i];
        cout << sum1-sum2 << endl;
    }
    */

    /*JEDAN NACIN
    while(m--){
        int a,b;
        cin >> a >> b;
        int64_t sum=0;
        for(int i=a; i<=b; i++){
            sum+=array[i];
        }
        cout << sum << endl;
    }
    */
    //DRUGI NACIN
    while(m--){
        int a,b;
        cin >> a >> b;
        cout << prefix[b+1]-prefix[a] << endl;
    }

    return 0;
}
