#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int64_t r;
    cin >> r;
    int64_t n;
    cin >> n;
    vector<int64_t> visine(n);
    for(int i=0; i<n; i++){
        cin >> visine[i];
    }
    sort(begin(visine),end(visine));
    vector<int64_t> it;
    it = unique(begin(visine),end(visine));
    visine.resize(begin(visine),it);
    int64_t num=0;
    for(int i=0; i<n; i++){
        if(binary_search(begin(visine),end(visine),visine[i]+r)){
            num++;
        }
    }
    cout << num << endl;
    return 0;
}
