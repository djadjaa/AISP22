#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int64_t n,k,x;
    cin >> n >> k >> x;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    sort(begin(a),end(a));
    int64_t i=0, j=n-1;
    while(j-i>=k){ //vrsimo inkrementaciju/dekrementaciju sve dok ne dodjemo do segmenta veličine k
        if(abs(a[i]-x) <= abs(a[j]-x))
            j--;
        else
            i++;
    }
    for(int br=i; br<=k; br++)
        cout << a[br] << ' ';
    cout << endl;

    return 0;
}
