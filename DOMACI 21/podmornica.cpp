#include <bits/stdc++.h>

using namespace std;

int main(){

    int64_t n,p;
    cin >> n >> p;
    vector<int64_t> h(n);
    for(int i=0; i<n; i++){
        cin >> h[i];
    }
    sort(begin(h),end(h));
    vector<int64_t> ps(n+1);
    partial_sum(begin(h),end(h),begin(ps));
    int64_t tempMaxDepth = -1, minMaxDepth = INT_MAX;
    for(int i=0; i<n; i++){
        tempMaxDepth = (p+ps[i])/(i+1);
        minMaxDepth = min(minMaxDepth,tempMaxDepth);
    }
    cout << minMaxDepth << endl;
    return 0;
}
