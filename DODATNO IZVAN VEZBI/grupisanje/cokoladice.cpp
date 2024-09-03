#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(){

    int64_t n,k;
    cin >> n;
    vector<int64_t> paketi(n);
    for(int i=0; i<n; i++){
        cin >> paketi[i];
    }
    cin >> k;
    sort(begin(paketi),end(paketi));
    int64_t mindiff=INT_MAX;
    for(int i=0; i+k-1<n; i++){
        mindiff=min(mindiff,paketi[i+k-1]-paketi[i]);
    }
    cout << mindiff << endl;
    return 0;
}
