#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){

    int64_t n,uk=0;
    cin >> n;
    vector<int64_t> k(n);
    for(int i=0; i<n; i++){
        cin >> k[i];
        uk += k[i];
    }
    int64_t minKilometraza=INT_MAX, dan, razl;
    int64_t levaPolovina=0,desnaPolovina=uk;
    for(int i=0; i<n; i++){
        levaPolovina += k[i];
        desnaPolovina -= k[i];
        razl = abs(desnaPolovina-levaPolovina);
        if(razl<minKilometraza){
            minKilometraza=razl;
            dan=i;
        }
    }
    cout << dan << '\n';
    return 0;
}
