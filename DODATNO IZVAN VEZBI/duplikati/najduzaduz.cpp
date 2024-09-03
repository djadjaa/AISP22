/*
 7
0 0 0 0 0 1
0 0 0 0 1 0
0 0 0 1 0 0
0 0 0 1 0 1
0 0 0 1 1 0
0 0 0 0 1 1
0 0 0 1 1 1
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int64_t n;
    cin>> n;
    vector<vector<int64_t>> duz(n,vector<int64_t> (6));
    vector<int64_t> sum(n);
    for(int i = 0; i < n; i++){
        sum[i] = 0;
        for(int j = 0; j < 6; j++){
            cin >> duz[i][j];
            sum[i] += duz[i][j];
        }
    }

    /*
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 6; j++){
            cout << duz[i][j] << " " ;
        }
        cout << endl;
    }
    */

    /*
    for(int i=0; i<n; i++)
        cout << sum[i] << " ";
    cout << endl;
    */
    sort(begin(sum),end(sum));
    int64_t rez=1;
    for(int i=1; i<n; i++){
        if(sum[i]!=sum[i-1])
            rez++;
    }
    cout << rez << endl;
    return 0;
}
