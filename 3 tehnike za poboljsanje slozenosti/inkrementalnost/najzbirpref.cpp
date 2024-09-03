#include <iostream>
#include <vector>

using namespace std;

int main(){

    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    int64_t sum=0,maxsum=sum;
    for(int i=0; i<n; i++){
        cin >> a[i];
        sum+=a[i];
        if(sum>maxsum)
            maxsum = sum;
    }
    cout << maxsum << endl;
    return 0;
}
