#include <iostream>
#include <vector>
using namespace std;

int main(){

    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int64_t maxsum=0,i=0;
    while(i<n){
        int64_t sum=0,j;
        for(j=i; j<n; j++){
            sum += a[j];
            if(sum<0){ //preskačemo negativne zbirove jer nisu zagarantovano maksimalni
                break;
            }
            if(sum>maxsum){
                maxsum=sum;
            }
        }
        i=j+1;
    }
    cout << maxsum << endl;
    return 0;
}
