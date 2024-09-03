#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int64_t n,d;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    cin >> d;
    sort(begin(a),end(a));
    int i=0;
    int64_t res=0;
    for(int j=0; j<n; j++){
        while(i<j && a[j]-a[i]>=d){
            i++;
        }
        res = max(res,a[j]-a[i]);
    }
    cout << res << endl;
    return 0;
}

/*
 7 1 3 8
 d=3
 => 1 3 7 8
 i=0,j=1
 3-1=2<d j++ (j=2)
 7-1=6>d i++ (i=1)
 7-3=4>d i++ (i=2)
 i=j => j++ (j=3)
 8-3=5>d i++ (i=3)
 i=j => kraj algoritma
 */
