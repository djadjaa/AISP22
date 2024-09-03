#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main(){

    int64_t t,m;
    cin >> t;
    vector<int64_t> tastature(t);
    for(int i=0; i<t; i++){
        cin >> tastature[i];
    }
    sort(begin(tastature),end(tastature));
    cin >> m;
    vector<int64_t> misevi(m);
    for(int i=0; i<m; i++){
        cin >> misevi[i];
    }
    sort(begin(misevi),end(misevi));
    int64_t z,maksimum=INT_MIN,rez,ztemp;
    cin >> z;
    int64_t i=0,j=m-1;
    while(i<t && j>=0){
        ztemp=tastature[i]+misevi[j];
        if(ztemp<=z){
            rez=ztemp;
            maksimum = max(maksimum,rez);
            i++;
        }else{
            j--;
        }
    }
    cout << maksimum << '\n';
    return 0;
}
