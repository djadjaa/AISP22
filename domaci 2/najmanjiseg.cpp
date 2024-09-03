#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(){

    int64_t n,z;
    cin >> n >> z;
    int64_t x, sum=0;
    unordered_map<int64_t,int64_t> ps;
    ps[0]=0;
    int64_t minSeg = n+1, minStart = -1, minEnd = -1;
    for(int64_t i=0; i<n; i++){
        cin >> x;
        sum += x;

        auto it = ps.find(sum-z);
        if(it!=ps.end()){
            int64_t tempInd = it->second;
            int64_t lenght = i - tempInd + 1;
            if(lenght < minSeg){
                minSeg = lenght;
                minStart = tempInd;
                minEnd = i;
            }
        }
        ps[sum]=i+1;
    }
    cout << minStart << ' ' << minEnd << endl;
    return 0;
}
