#include <iostream>
#include <vector>

using namespace std;

int main(){

    int64_t n;
    cin >> n;
    vector<int64_t> zgrade(n);
    vector<int64_t> visine(n);
    for(int i=0; i<n; i++){
        cin >> zgrade[i];
    }
    int64_t max=0;
    for(int i=n-1; i>=0; i--){
        if(zgrade[i]>max)
            max=zgrade[i];
        visine[i]=max;
    }
    for(int i=0; i<n; i++)
        cout << visine[i] << endl;
    return 0;
}
