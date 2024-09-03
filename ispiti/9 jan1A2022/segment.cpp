/*
 5 2
  1 4 -3 5 2
0 1 5 2 7 9
map<prefiksnasuma,indeks_na_kojoj_se_nalazi_suma> ps
ps[0]=0;
for(i=0, i<n,i++){
    ps = 1;
    ps[1-2] = ps[-1] = end = > ps[ps] = i+1 => ps[1] = 1
    ps = 5;
    ps[5-2] = ps[3] = end => ps[5] = 2
    ps = 2;
    ps[2-2] = ps[0] != end => j=0 i=2 duzina = j-i+1=3 + ps[2]=3
    ps = 7
    ps[7-2] = ps[5] != end => j=2 i=3 duzina = 2-3+1=0 + ps[7]=4
    ps = 9
    ps[9-2] = ps[7] != end => j=4 i=4 duzina = 1 + ps[9]=5
}
kraj algo:
rez je j=2 i=3 (jer daju duzinu segmenta 0)
 */
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main(){

    int64_t n,z;
    cin >> n >> z;
    int64_t prefixSum=0;
    unordered_map<int64_t,int64_t> ps;
    ps[0]=0;
    int64_t x;
    int64_t minL=n+1, minPoc=-1, minKraj=-1;
    for(int i=0; i<n; i++){
        cin >> x;
        prefixSum += x;
        auto it = ps.find(prefixSum-z);
        if(it != ps.end()){
            int res = it->second;
            int64_t lenght = i-res+1; //duzina segmenta clanova koji daju zbir z
            if(lenght < minL){
                minL = lenght;
                minPoc = res;
                minKraj = i;
            }
        }
        ps[prefixSum] = i+1;
    }
    if(minPoc!=-1)
        cout << minPoc << ' ' << minKraj << endl;
    else
        cout << "nema\n";
    return 0;
}
