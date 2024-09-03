#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int64_t n,t;
    cin >> n >> t;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    sort(begin(a),end(a)); //u pitanju su uzastopni brojevi
    int i=0,j=0,k=-1;
    int64_t sum=a[0]; //inicijalizujemo sumu
    while(j<n){
        if(sum < t){
            j++;
            sum += a[j];
            k=max(k,j-i+1); //j-i+1 je duzina segmenta
        }
        else{
            sum -= a[i];
            i++;
        }
    }
    if(k==-1)
        cout << 0 << endl;
    else
        cout << k << endl;
    return 0;
}
